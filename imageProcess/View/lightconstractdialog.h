#pragma once
#include <QDialog>
#include <QSlider>
#include <QSpinBox>
#include <memory>
#include "../Common/Command.h"

namespace Ui {
class LightConstractDialog;
}

class LightConstractDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LightConstractDialog(QWidget *parent = nullptr);
    ~LightConstractDialog();
    void setLightContrastCommand(std::shared_ptr<Command> lightContrastCommand);
    void setTmpLightContrastCommand(std::shared_ptr<Command> tmpLightContrastCommand);
    void setDisplayNowCommand(std::shared_ptr<Command> displayNowCommand);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_contrastBoard_valueChanged(int arg1);

    void on_lightBoard_valueChanged(int arg1);

    void on_contrastSlide_valueChanged(int value);

    void on_lightSlide_valueChanged(int value);

private:
    Ui::LightConstractDialog *ui;
    QSpinBox* lightBoard;
    QSpinBox* contrastBoard;
    QSlider* lightSlider;
    QSlider* contrastSlider;
    std::shared_ptr<Command> lightContrastCommand;
    std::shared_ptr<Command> tmpLightContrastCommand;
    std::shared_ptr<Command> displayNowCommand;
};
