#ifndef KEYWORDS_H
#define KEYWORDS_H

#include <QtCore>


class Keywords : public QAbstractListModel
{
    Q_OBJECT

public:
    Keywords(QObject *parent = Q_NULLPTR);

    static QVector<QString> ListOfStylableWidgets;
    static QMap<QString, QString> MapOfProperties;
    static QVector<QString> ListOfIcons;
    static QMap<QString, QVector<QString>> MapOfPropertyTypes;
    static QVector<QString> ListOfPseudoStates;
    static QVector<QString> ListOfSubControls;

    // Znaki indentyfikacyjne
    enum Identifier {IClass, IProperty, IControl, IValue, IState };
    static QChar ListOfIdentifiers[];

    // Należy podać czystą listę
    static bool getFromPropertyType (const QString type, QStringList &out, int deep = 0);

    void setList(const QStringList &list) {mList = list.toVector();}

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

public slots:
    void isDoubleClicked(const QModelIndex &index);
    void isClicked(const QModelIndex &index);

signals:
    void doubleClicked(const QString &index);
    void clicked(bool);

private:
    QVector<QString> mList;

};

bool removeFromQStringListMismatched(QList<QString> &inOut, const QString prefix);

#endif // KEYWORDS_H
