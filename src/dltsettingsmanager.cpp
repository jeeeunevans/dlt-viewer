#include "dltsettingsmanager.h"

DltSettingsManager *DltSettingsManager::m_instance = NULL;

DltSettingsManager* DltSettingsManager::instance()
{
    if(!m_instance)
        m_instance = new DltSettingsManager();
    return m_instance;
}

void DltSettingsManager::close()
{
    if(m_instance)
        delete m_instance;
    m_instance = NULL;
}

#ifdef __WIN32__
DltSettingsManager::DltSettingsManager()
{
    settings = new QSettings("config.ini", QSettings::IniFormat);
}
#else
DltSettingsManager::DltSettingsManager()
{
    settings = new QSettings(QSettings::IniFormat, QSettings::UserScope, "BMW","DLT Viewer");
}
#endif

DltSettingsManager::~DltSettingsManager()
{
    delete settings;
}

void DltSettingsManager::setValue(const QString &key, const QVariant &value)
{
    settings->setValue(key, value);
}

QVariant DltSettingsManager::value(const QString &key, const QVariant &defaultValue) const
{
    return settings->value(key, defaultValue);
}

void DltSettingsManager::clear()
{
    settings->clear();
}

QString DltSettingsManager::fileName() const
{
    return settings->fileName();
}
