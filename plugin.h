#pragma once

#include <extensionsystem/iplugin.h>

#include <QStringList>

namespace LayoutSupport::Internal {

class LayoutSupportPlugin : public ExtensionSystem::IPlugin {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE
                          "layoutsupport.json")

public:
    LayoutSupportPlugin();
    bool initialize(const QStringList &arguments,
                    QString *errorString) override;
    void extensionsInitialized() override;
};

} // namespace LayoutSupport::Internal
