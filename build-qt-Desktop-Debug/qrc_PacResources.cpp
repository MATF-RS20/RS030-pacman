/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.9.5
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

static const unsigned char qt_resource_data[] = {
  // /home/ariel/RS030-pacman/qt/mapa.txt
  0x0,0x0,0x0,0x81,
  0x0,
  0x0,0x2,0xec,0x78,0x9c,0xad,0x92,0xcb,0xd,0xc0,0x20,0xc,0x43,0xef,0x5e,0x23,
  0xb,0xe0,0xfd,0x97,0x6b,0x45,0x7e,0xa4,0x80,0xe0,0xd0,0x8,0x11,0x3d,0x89,0x38,
  0xe,0x40,0x1e,0x2,0x6c,0x1a,0xdb,0xfc,0x9e,0xa0,0xae,0x5d,0xbe,0x3a,0x51,0x43,
  0x59,0x92,0x11,0x5,0x5e,0xf6,0x65,0xd5,0xa0,0xaf,0xdc,0x82,0x41,0x96,0xbe,0x9c,
  0x18,0xbd,0x82,0x66,0x61,0x95,0x4d,0x23,0xfa,0x72,0x62,0xb8,0x65,0xd6,0xa1,0x92,
  0x5d,0xc3,0x54,0x43,0x23,0xb9,0xfb,0x90,0x50,0x8d,0xfe,0xc9,0x17,0x3e,0xfe,0x79,
  0xb9,0x96,0x53,0xc4,0x5d,0x4a,0x32,0xcc,0x11,0xb7,0xf9,0xe6,0x5d,0xda,0x60,0x7f,
  0x95,0x7d,0x16,0x19,0xac,0xd4,0xcb,0xc5,0xe9,0x23,0x13,0xf,0x7e,0x43,0x8a,0x30,
  
  
};

static const unsigned char qt_resource_name[] = {
  // new
  0x0,0x3,
  0x0,0x0,0x74,0xc7,
  0x0,0x6e,
  0x0,0x65,0x0,0x77,
    // PacFiles
  0x0,0x8,
  0x7,0x7d,0x8,0x3,
  0x0,0x50,
  0x0,0x61,0x0,0x63,0x0,0x46,0x0,0x69,0x0,0x6c,0x0,0x65,0x0,0x73,
    // mapa.txt
  0x0,0x8,
  0x8,0x64,0x55,0x94,
  0x0,0x6d,
  0x0,0x61,0x0,0x70,0x0,0x61,0x0,0x2e,0x0,0x74,0x0,0x78,0x0,0x74,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/new
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x2,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/new/PacFiles
  0x0,0x0,0x0,0xc,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x3,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/new/PacFiles/mapa.txt
  0x0,0x0,0x0,0x22,0x0,0x1,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x6f,0x2e,0xb1,0xd3,0x5d,

};

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

bool qUnregisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_PacResources)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_PacResources)()
{
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (0x2, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_PacResources)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_PacResources)()
{
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (0x2, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_PacResources)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_PacResources)(); }
   } dummy;
}
