#include "plugin.h"

#include <coreplugin/icore.h>

#include <QBoxLayout>
#include <QWidget>

namespace LayoutSupport::Internal {

LayoutSupportPlugin::LayoutSupportPlugin() {}

bool LayoutSupportPlugin::initialize(
    [[maybe_unused]] const QStringList &arguments,
    [[maybe_unused]] QString *errorString) {
    QMainWindow *mainWindow = Core::ICore::mainWindow();
    mainWindow->layout()->setSpacing(0);

    auto *wrapper = new QWidget(mainWindow);
    wrapper->setObjectName("LayoutSupportWrapper");
    wrapper->setMinimumHeight(0);

    auto *layout = new QVBoxLayout();
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);

    layout->addWidget(mainWindow->centralWidget());

    wrapper->setLayout(layout);

    mainWindow->setCentralWidget(wrapper);
    return true;
}

void LayoutSupportPlugin::extensionsInitialized() {}

} // namespace LayoutSupport::Internal
