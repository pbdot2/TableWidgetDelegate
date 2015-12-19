#ifndef INPUTDELEGATE_H
#define INPUTDELEGATE_H

#include <QItemDelegate>

class InputDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit InputDelegate(QObject *parent = 0);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;

signals:

public slots:
        void emitCommitData();

};

#endif // INPUTDELEGATE_H
