#ifndef HL_VM_H
#define HL_VM_H

#include <QObject>
#include <QStringList>

class VM: public QObject {
    Q_OBJECT

    Q_PROPERTY(
        bool rootIsVisible
        READ rootIsVisible
        WRITE rootSetIsVisible
        NOTIFY rootDidChangeIsVisible
    )

    Q_PROPERTY(
        QStringList rootItems
        READ rootItems
        NOTIFY rootDidChangeItems
    )

    private:
        VM();

    public:
        VM(VM const &) = delete;
        void operator=(VM const &) = delete;
        virtual ~VM() { }
        static VM &singleton() {
            static VM instance;
            return instance;
        }

    public:
        bool rootIsVisible() const;
        QStringList rootItems() const;

    public slots:
        void rootSetIsVisible(bool value);
        void rootSetItems(QStringList items);

    signals:
        void rootDidChangeIsVisible(bool value);
        void rootDidChangeItems(QStringList items);

    private:
        bool _rootIsVisible;
        QStringList _rootItems;
};

#endif // HL_VM_H
