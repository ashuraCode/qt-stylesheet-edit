#include "ashurawind.h"
#include "ui_ashurawind.h"

AshuraWind::AshuraWind(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AshuraWind),
    mFileDialog(this, QStringLiteral("Wybierz stylesheet"), QDir::currentPath(), tr("Stylesheet (*.stylesheet)")),
    mSettings(QSettings::IniFormat, QSettings::UserScope, "Ashura", "StylesheetEditor")
{
    ui->setupUi(this);

    mFileDialog.setDefaultSuffix(".stylesheet");
    mFileDialog.setOption(QFileDialog::DontUseNativeDialog, true);

    loadSettings();
}

AshuraWind::~AshuraWind()
{
    delete ui;
}

void AshuraWind::on_qwidgetsList_currentRowChanged(int currentRow)
{

}

void AshuraWind::on_qpropertiesList_currentRowChanged(int currentRow)
{
    ui->qPropStack->setCurrentIndex(currentRow);
}

void AshuraWind::on_qvartypes_currentRowChanged(int currentRow)
{
    ui->qtypeStack->setCurrentIndex(currentRow);
}

void AshuraWind::on_qstatesList_currentRowChanged(int currentRow)
{
    ui->qstatesStack->setCurrentIndex(currentRow);
}

void AshuraWind::on_qactionList_currentRowChanged(int currentRow)
{
    ui->qactionStack->setCurrentIndex(currentRow);
}

void AshuraWind::loadSettings()
{
    ui->menuOstatnie->clear();
    int size = mSettings.beginReadArray("history");
    for (int i = 0; i < size; ++i) {
        mSettings.setArrayIndex(i);
        QAction *action = new QAction(mSettings.value("last").toString());
        ui->menuOstatnie->addAction(action);
        connect(action, SIGNAL(triggered(bool)), this, SLOT(actionOtw_rzTriggered(bool)));
    }
    mSettings.endArray();
}

void AshuraWind::saveSettings()
{
    mSettings.clear();
    const QList<QAction*> actions = ui->menuOstatnie->actions();
    mSettings.beginWriteArray("history", actions.size());
    int i = 0;
    for (auto &s : actions) {
        mSettings.setArrayIndex(i++);
        mSettings.setValue("last", s->text());
    }
    mSettings.endArray();
}

void AshuraWind::addToHistory(const QString &file)
{
    if (!file.isEmpty()) {
        const QList<QAction*> actions = ui->menuOstatnie->actions();
        if (actions.count()>0) {
            if (actions.front()->text().compare("empty")==0) {
                ui->menuOstatnie->clear();
            }
        }
        for (auto &s : actions) {
            if (s->text().compare(file)==0) {
                if (actions.size()>1) {
                    ui->menuOstatnie->removeAction(s);
                    ui->menuOstatnie->insertAction(ui->menuOstatnie->actions().front(), s);
                    saveSettings();
                }
                return;
            }
        }
        QAction *action = new QAction(file);
        if (actions.size()>0)
            ui->menuOstatnie->insertAction(actions.front(), action);
        else
            ui->menuOstatnie->addAction(action);

        connect(action, SIGNAL(triggered(bool)), this, SLOT(actionOtw_rzTriggered(bool)));

        saveSettings();
    }
}

void AshuraWind::on_qiconsList_currentRowChanged(int currentRow)
{

}

void AshuraWind::on_qedytor_textChanged()
{
    ui->qtab->currentWidget()->setStyleSheet(ui->qedytor->toPlainText());
}

void AshuraWind::on_qtab_currentChanged(int index)
{
    on_qedytor_textChanged();
}

#define QSAVE_MODE(dialog) \
    dialog.setFileMode(QFileDialog::AnyFile); \
    dialog.setAcceptMode(QFileDialog::AcceptSave);

#define QOPEN_MODE(dialog) \
    dialog.setFileMode(QFileDialog::ExistingFile); \
    dialog.setAcceptMode(QFileDialog::AcceptOpen);

#define GET_QFileDialog_FILE(dialog) \
    (dialog.selectedFiles().count()>0)?(mFileDialog.selectedFiles().front()):("");

void AshuraWind::on_actionOtw_rz_triggered()
{
    QOPEN_MODE(mFileDialog)
    mFileDialog.exec();
    QString file = GET_QFileDialog_FILE(mFileDialog);

    openFile(file);
}

void AshuraWind::actionOtw_rzTriggered(bool)
{
    QAction *action = qobject_cast<QAction*>(sender());
    if (action!=NULL) {
        openFile(action->text());
    }
}

void AshuraWind::openFile(const QString &file)
{
    if (!file.isEmpty()) {
        QFile qfile(file);
        if (qfile.open(QFile::ReadOnly)) {
            ui->qedytor->setPlainText(qfile.readAll());
            addToHistory(file);
        }
        qfile.close();
    }
}

void AshuraWind::on_actionZapisz_triggered()
{
    QSAVE_MODE(mFileDialog)
    mFileDialog.exec();
    QString file = GET_QFileDialog_FILE(mFileDialog);

    if (!file.isEmpty()) {
        QFile qfile(file);
        if (qfile.open(QFile::WriteOnly)) {
            qfile.write(ui->qedytor->toPlainText().toUtf8());
            addToHistory(file);
        }
        qfile.close();
    }
}

void AshuraWind::on_actionAutor_triggered()
{
    QMessageBox::information(NULL, "Autor",
                             QStringLiteral("AshuraCode"), QMessageBox::Ok);
}

