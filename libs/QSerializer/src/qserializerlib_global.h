#ifndef QJSONMARSHALERLIB_GLOBAL_H
#define QJSONMARSHALERLIB_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QtXml/QtXml>

#if defined(QSERIALIZER_LIBRARY)
#  define QSERIALIZER_EXPORT Q_DECL_EXPORT
#else
#  define QSERIALIZER_EXPORT Q_DECL_IMPORT
#endif

#endif // QJSONMARSHALERLIB_GLOBAL_H