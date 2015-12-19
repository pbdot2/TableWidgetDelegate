#include "inputdelegate.h"
#include <QComboBox>
#include <QDebug>

InputDelegate::InputDelegate(QObject *parent) :
    QItemDelegate(parent)
{
}

QWidget *InputDelegate::createEditor(QWidget *parent,
                                     const QStyleOptionViewItem & /* option */,
                                     const QModelIndex &index) const
{
    QComboBox *comboBox = new QComboBox(parent);
    comboBox->addItem(tr("HDMI"));
    comboBox->addItem(tr("DVI"));
    comboBox->addItem(tr("VGA"));

    connect(comboBox, SIGNAL(activated(int)), this, SLOT(emitCommitData()));

    return comboBox;
}

void InputDelegate::setEditorData(QWidget *editor,
                                  const QModelIndex &index) const
{
    QComboBox *comboBox = qobject_cast<QComboBox *>(editor);
    if (!comboBox)
        return;

    int pos = comboBox->findText(index.model()->data(index).toString(),
                                 Qt::MatchExactly);
    comboBox->setCurrentIndex(pos);
}

void InputDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                 const QModelIndex &index) const
{
    QComboBox *comboBox = qobject_cast<QComboBox *>(editor);
    if (!comboBox)
        return;

    model->setData(index, comboBox->currentText());
}

void InputDelegate::emitCommitData()
{
    emit commitData(qobject_cast<QComboBox *>(sender()));
}
