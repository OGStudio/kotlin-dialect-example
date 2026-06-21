#ifndef HL_VM_H
#define HL_VM_H

#include <QObject>

class VM: public QObject {
    Q_OBJECT

    Q_PROPERTY(
        bool rootIsVisible
        READ rootIsVisible
        WRITE rootSetIsVisible
        NOTIFY rootDidChangeIsVisible
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

    public slots:
        void rootSetIsVisible(bool value);

    signals:
        void rootDidChangeIsVisible(bool value);

    private:
        bool _rootIsVisible;
};

#endif // HL_VM_H
