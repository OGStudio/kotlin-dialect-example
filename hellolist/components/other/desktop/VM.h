#ifndef HL_VM_H
#define HL_VM_H

#include <QList>
#include <QObject>
#include <QQmlListProperty>

#include "KT.h"

class VM: public QObject {
    Q_OBJECT

    Q_PROPERTY(
        bool rootIsVisible
        READ rootIsVisible
        WRITE rootSetIsVisible
        NOTIFY rootDidChangeIsVisible
    )

    Q_PROPERTY(
        QQmlListProperty<Item> rootItems
        READ rootItems
        NOTIFY rootDidChangeItems
    )

    private:
        VM();

    public:
        VM(VM const &) = delete;
        void operator=(VM const &) = delete;
        virtual ~VM();
        static VM &singleton() {
            static VM instance;
            return instance;
        }

    public:
        bool rootIsVisible() const;

        QQmlListProperty<Item> rootItems() const;
        static Item *rootItemsAt(QQmlListProperty<Item> *list, qsizetype index);
        static qsizetype rootItemsCount(QQmlListProperty<Item> *list);

    public slots:
        void rootSetIsVisible(bool value);
        void rootSetItems(QList<Item*> items);

    signals:
        void rootDidChangeIsVisible(bool value);
        void rootDidChangeItems();

    private:
        bool _rootIsVisible;
        QList<Item*> _rootItems;
};

#endif // HL_VM_H
