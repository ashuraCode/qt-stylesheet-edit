#include "ptextedit.h"


PTextEdit::PTextEdit(QWidget *parent) : QTextEdit(parent)
{
    init();
}

PTextEdit::PTextEdit(const QString &text, QWidget *parent) : QTextEdit(text, parent)
{
    init();
}

PTextEdit::~PTextEdit()
{

}

void PTextEdit::init()
{
    mHighlighter = new Highlighter(document());
    mShortcut = new QShortcut(QKeySequence("Ctrl+Space"), this);
    connect(mShortcut, SIGNAL(activated()), this, SLOT(showPopup()));
    mModel = new Keywords;

    mCompleterWdt = new QWidget;
    mCompleterWdt->setAttribute(Qt::WA_ShowWithoutActivating);
    QHBoxLayout *lay = new QHBoxLayout;
    lay->setMargin(0);
    mCompleter = new QListView;
    lay->addWidget(mCompleter);
    mCompleterWdt->setLayout(lay);
    mCompleterWdt->setFixedSize(200, 150);

    QObject::connect(mCompleter, SIGNAL(doubleClicked(QModelIndex)),
                     mModel, SLOT(isDoubleClicked(QModelIndex)));
    QObject::connect(mCompleter, SIGNAL(pressed(QModelIndex)),
                     mModel, SLOT(isClicked(QModelIndex)));
    QObject::connect(mModel, SIGNAL(doubleClicked(QString)),
                     this, SLOT(insertCompletion(QString)));
    QObject::connect(mModel, SIGNAL(clicked(bool)), mCompleterWdt, SLOT(setVisible(bool)));
}

void PTextEdit::keyPressEvent(QKeyEvent *e)
{
    int key = e->key();

    if ( mCompleterWdt->isVisible() ) {
        if (key==Qt::Key_Enter || key==Qt::Key_Return) {
            QModelIndex curr = mCompleter->currentIndex();
            insertCompletion(mModel->data(curr).toString());
            return;
        } else if (key==Qt::Key_Escape) {
            mCompleterWdt->hide();
        } else if (key==Qt::Key_Up || key==Qt::Key_Down) {
            int curr = mCompleter->currentIndex().row();
            if (curr>0 && key==Qt::Key_Up)
                mCompleter->setCurrentIndex(mModel->index(curr-1));
            if (curr<(mModel->rowCount()-1) && key==Qt::Key_Down)
                mCompleter->setCurrentIndex(mModel->index(curr+1));
            return;
        }
    }

    QTextEdit::keyPressEvent(e);

    if (key==Qt::Key_BraceLeft) {
        QTextCursor tc = textCursor();
        tc.insertText("\r\n\t\r\n}");
        tc.movePosition(QTextCursor::PreviousBlock);
        tc.movePosition(QTextCursor::EndOfBlock);
        setTextCursor(tc);
    }
}

void PTextEdit::focusOutEvent(QFocusEvent *e)
{
    mCompleterWdt->hide();
    QTextEdit::focusOutEvent(e);
}

void PTextEdit::showPopup()
{
    Keywords::Identifier ident;
    QString type;
    QStringList autocommpleteList;
    mIncomplete.clear();

    if (searchForIdentifier(ident, mIncomplete, type)) {
        switch (ident) {
        case Keywords::IClass:
            autocommpleteList = Keywords::ListOfStylableWidgets.toList();
            break;
        case Keywords::IProperty:
            autocommpleteList = Keywords::MapOfProperties.keys();
            break;
        case Keywords::IValue:
            Keywords::getFromPropertyType(type, autocommpleteList);
            break;
        case Keywords::IControl:
            autocommpleteList = Keywords::ListOfSubControls.toList();
            break;
        case Keywords::IState:
            autocommpleteList = Keywords::ListOfPseudoStates.toList();
            break;
        default:
            qDebug() << "searchForIdentifier zwrócił zły Identyfikator";
            return;
        }
        removeFromQStringListMismatched(autocommpleteList, mIncomplete);

        if (autocommpleteList.size()>0) {
            if (autocommpleteList.size()==1) {
                insertCompletion(autocommpleteList.front());
            } else {
                mCompleter->setModel(NULL);
                mModel->setList(autocommpleteList);
                mCompleter->setModel(mModel);
                mCompleter->setCurrentIndex(mModel->index(0));

                mCompleterWdt->move(mapToGlobal(cursorRect().bottomRight()));

                mCompleterWdt->setWindowFlags(Qt::SplashScreen | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
                mCompleterWdt->show();
            }
        }
    } else {
        qDebug() << "błąd wyszukiwania";
    }
}

bool PTextEdit::searchForIdentifier(Keywords::Identifier &out, QString &incompleteWord, QString &valueType)
{
    static const QChar DASH('-');
    int inTextPosition = textCursor().position()-1;
    if (inTextPosition<0) {out = Keywords::IClass; return true;}
    QChar c = document()->characterAt(inTextPosition);

    incompleteWord.clear();

    while(c.isLetter() || c==DASH) {
        incompleteWord.push_front(c);
        --inTextPosition;
        c = document()->characterAt(inTextPosition);
    }

    while(c.isSpace()) {
        --inTextPosition;
        c = document()->characterAt(inTextPosition);
    }

    if (inTextPosition<0) {out = Keywords::IClass; return true;}

    if (c == Keywords::ListOfIdentifiers[0]) {
        out = Keywords::IClass;
    }
    if (c == Keywords::ListOfIdentifiers[1]) {
        out = Keywords::IProperty;
    }
    if (c == Keywords::ListOfIdentifiers[2]) {
        out = Keywords::IProperty;
    }
    if (c == Keywords::ListOfIdentifiers[3]) {
        out = Keywords::IState;
        if (inTextPosition>0) {
            --inTextPosition;
            c = document()->characterAt(inTextPosition);

            if (c == Keywords::ListOfIdentifiers[3]) {
                out = Keywords::IControl;
            } else {

                while(c.isSpace()) {
                    --inTextPosition;
                    c = document()->characterAt(inTextPosition);
                }

                QString word;

                while(c.isLetter() || c==DASH) {
                    word.push_front(c);
                    --inTextPosition;
                    c = document()->characterAt(inTextPosition);
                }

                if (Keywords::MapOfProperties.keys().contains(word)) {
                    out = Keywords::IValue;
                    valueType = Keywords::MapOfProperties[word];
                }
            }
        }
    }

    return true;
}

void PTextEdit::insertCompletion(const QString& completion)
{
    mCompleterWdt->hide();
    QTextCursor tc = textCursor();
    int extra = completion.length() - mIncomplete.length();
    tc.insertText(completion.right(extra));
    setTextCursor(tc);
}
