#ifndef BUTTONDELEGATE_H
#define BUTTONDELEGATE_H

#include <QItemDelegate>

class ButtonDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit ButtonDelegate(QObject *parent = 0);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;

signals:

public slots:
    void emitClicked(int i);

};

#endif // BUTTONDELEGATE_H
