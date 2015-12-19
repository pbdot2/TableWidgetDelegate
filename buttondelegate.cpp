#include "buttondelegate.h"
#include <QPushButton>
#include <QDebug>

ButtonDelegate::ButtonDelegate(QObject *parent) :
    QItemDelegate(parent)
{
}

QWidget *ButtonDelegate::createEditor(QWidget *parent,
                                     const QStyleOptionViewItem & /* option */,
                                     const QModelIndex &index) const
{
    QPushButton *btn = new QPushButton("On", parent);
    connect(btn, SIGNAL(clicked()), this, SLOT(emitClicked(int)));
    return btn;
}

void ButtonDelegate::setEditorData(QWidget *editor,
                                  const QModelIndex &index) const
{

}

void ButtonDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                 const QModelIndex &index) const
{

}

void ButtonDelegate::emitClicked(int i)
{
emit commitData(qobject_cast<QWidget *>(sender()));
}
