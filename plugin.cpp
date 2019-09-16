#include "plugin.h"

#include <coreplugin/icore.h>

#include <QBoxLayout>
#include <QWidget>

namespace LayoutSupport::Internal {

LayoutSupportPlugin::LayoutSupportPlugin() noexcept {}

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

ExtensionSystem::IPlugin::ShutdownFlag LayoutSupportPlugin::aboutToShutdown() {
    QMainWindow *mainWindow = Core::ICore::mainWindow();
    auto *wrapper = mainWindow->centralWidget();
    auto *originalCentralWidget =
        wrapper->layout()->itemAt(wrapper->layout()->count() - 1)->widget();

    mainWindow->setCentralWidget(originalCentralWidget);
    delete wrapper;

    return SynchronousShutdown;
}

} // namespace LayoutSupport::Internal
