#ifndef PTEXTEDIT_H
#define PTEXTEDIT_H

#include <QtWidgets>
#include "highlighter.h"
#include "keywords.h"


class PTextEdit : public QTextEdit
{
    Q_OBJECT

public:
    explicit PTextEdit(QWidget *parent = Q_NULLPTR);
    explicit PTextEdit(const QString &text, QWidget *parent = Q_NULLPTR);
    virtual ~PTextEdit();

protected:
    void init();
    virtual void keyPressEvent(QKeyEvent *e) Q_DECL_OVERRIDE;
    virtual void focusOutEvent(QFocusEvent *e) Q_DECL_OVERRIDE;

protected slots:
    void showPopup();
    void insertCompletion(const QString& completion);

private:
    // Identyfikator plus offsety do już wpisanego tekstu
    bool searchForIdentifier(Keywords::Identifier &out, QString &incompleteWord, QString &valueType);

private:
    Highlighter *mHighlighter;
    QShortcut *mShortcut;
    QListView *mCompleter;
    QWidget *mCompleterWdt;
    Keywords *mModel;
    QString mIncomplete;
};

#endif // PTEXTEDIT_H
