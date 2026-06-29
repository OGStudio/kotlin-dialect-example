#ifndef HL_KT_H
#define HL_KT_H

#include "libhl_api.h"
#define KT libhl_symbols()->kotlin.root.org.opengamestudio
#define KTLibRef(NAME) libhl_kref_kotlin_##NAME
#define KTRef(NAME) libhl_kref_org_opengamestudio_##NAME
#define KTSym libhl_symbols()

#include <QList>
#include <QObject>
#include <QString>

class Item : public QObject {
    Q_OBJECT
    Q_PROPERTY(int id READ id CONSTANT)
    Q_PROPERTY(QString title READ title CONSTANT)

    public:
        Item(KTRef(Item) raw, QObject *parent = nullptr);

        int id() const;
        QString title() const;

    private:
        KTRef(Item) raw;
};

#endif // HL_KT_H
