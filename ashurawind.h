#ifndef ASHURAWIND_H
#define ASHURAWIND_H

#include <QtCore>
#include <QtWidgets>
#include "ptextedit.h"


namespace Ui {
class AshuraWind;
}

class AshuraWind : public QMainWindow
{
    Q_OBJECT

public:
    explicit AshuraWind(QWidget *parent = 0);
    ~AshuraWind();

private slots:
    void on_qwidgetsList_currentRowChanged    (int currentRow);
    void on_qpropertiesList_currentRowChanged (int currentRow);
    void on_qstatesList_currentRowChanged     (int currentRow);
    void on_qiconsList_currentRowChanged      (int currentRow);
    void on_qedytor_textChanged();
    void on_qtab_currentChanged(int index);
    void on_actionOtw_rz_triggered();
    void actionOtw_rzTriggered(bool);
    void openFile(const QString &file);
    void on_actionZapisz_triggered();
    void on_actionAutor_triggered();
    void on_qvartypes_currentRowChanged(int currentRow);
    void on_qactionList_currentRowChanged(int currentRow);

private:
    void loadSettings();
    void saveSettings();
    void addToHistory(const QString &file);

private:
    Ui::AshuraWind *ui;
    QFileDialog mFileDialog;
    QSettings mSettings;
};

#endif // ASHURAWIND_H
