#ifndef QJSONMARSHALER_H
#define QJSONMARSHALER_H
#include <qserializerlib_global.h>
#include <serializerexception.h>

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include <typeinfo>
#include <type_traits>

#define QS_METATYPE(Type) qRegisterMetaType<Type>(#Type) ;

#define QS_REGISTER(Type)       \
QS_METATYPE(Type)               \
QS_METATYPE(Type*)              \
QS_METATYPE(std::vector<Type*>) \
QS_METATYPE(std::vector<Type>)  \

namespace QSerializer
{
    /// \brief производит сериализацию QObject в JSON по имеющейся у объекта метаинформации
    QSERIALIZER_EXPORT QJsonObject toJson(QObject * qo);

    /// \brief производит сериализацию JSON в переданный QObject согласно имеющейся у объекта метаинформации
    QSERIALIZER_EXPORT void fromJson(QObject * qo, const QJsonObject & json);

    /// \brief производит сериализацию JSON в переданный QObject согласно имеющейся у объекта метаинформации
    QSERIALIZER_EXPORT void fromJson(QObject * qo, const QJsonDocument & json);

    /// \brief производит сериализацию JSON в переданный QObject согласно имеющейся у объекта метаинформации
    QSERIALIZER_EXPORT void fromJson(QObject * qo, const QByteArray & json);

    /// \brief производит JSON в переданный QObject согласно имеющейся у объекта метаинформации
    QSERIALIZER_EXPORT void fromJson(QObject * qo, const QString & json);


    /// \brief конвертирует JSON в новый объект указанного типа и возвращает указатель на него
    template <class T, typename = std::enable_if<std::is_base_of<QObject, T>::value>>
    QSERIALIZER_EXPORT T * fromJson(const QJsonObject &json)
    {
        T * targetObj = new T();
        fromJson(targetObj, json);
        return targetObj;
    }
    /// \brief конвертирует JSON в новый объект указанного типа и возвращает указатель на него
    template <class T, typename = std::enable_if<std::is_base_of<QObject, T>::value>>
    QSERIALIZER_EXPORT T * fromJson(const QJsonDocument & json)
    {
        QJsonObject jObject = json.object();
        return fromJson<T>(jObject);
    }

    /// \brief конвертирует JSON в новый объект указанного типа и возвращает указатель на него
    template <class T, typename = std::enable_if<std::is_base_of<QObject, T>::value>>
    QSERIALIZER_EXPORT T * fromJson(const QByteArray & json)
    {
        QJsonObject jObject = QJsonDocument::fromJson(json).object();
        return fromJson<T>(jObject);
    }

    /// \brief конвертирует JSON в новый объект указанного типа и возвращает указатель на него
    template <class T, typename = std::enable_if<std::is_base_of<QObject, T>::value>>
    QSERIALIZER_EXPORT T * fromJson(const QString &json)
    {
        const char * raw = json.toStdString().c_str();
        QJsonObject jObject = QJsonDocument::fromRawData(raw, static_cast<int>(strlen(raw))).object();
        return fromJson<T>(jObject);
    }

    /// \brief производит сериализацию QObject в XML по имеющейся у объекта метаинформации
    QSERIALIZER_EXPORT QDomDocument toXml(QObject * qo);

    /// \brief модифицирует существующий объект из XML
    QSERIALIZER_EXPORT void fromXml(QObject * qo, const QDomNode &xml);

    /// \brief конвертирует XML в новый объект указанного типа и возвращает указатель на него
    template <class T, typename = std::enable_if<std::is_base_of<QObject, T>::value>>
    QSERIALIZER_EXPORT T * fromXml(const QDomNode &xml)
    {
        T * targetObj = new T();
        fromXml(targetObj, xml);
        return targetObj;
    }
}






#endif // QJSONMARSHALER_H

