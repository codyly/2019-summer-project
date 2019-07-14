#pragma once
#include <memory>
#include <QImage>
#include "../Common/ImageList.h"
#include "Command/OpenFileCommand.h"
#include "Command/SaveFileCommand.h"
#include "Command/LightContrastCommand.h"
#include "Command/ToGrayCommand.h"
#include "Command/ToBibaryCommand.h"
#include "Command/DetectEdgeCommand.h"
#include "Command/GrayEqualizeHistCommand.h"
#include "Command/ColorEqualizeHistCommand.h"
#include "Command/LaplaceCommand.h"
#include "Command/LogEnhanceCommand.h"
#include "Command/GammaCorrectCommand.h"
#include "Command/AddGaussNoiseCommand.h"
#include "Command/AddSaltNoiseCommand.h"
#include "Command/ImageSegmentationCommand.h"

#include "../Common/Notification.h"
#include "Notification/UpdateDataNotification.h"

class Model;

class ViewModel
{
private:
    std::shared_ptr<Model> model;
    std::shared_ptr<OpenFileCommand> openFileCommand;
    std::shared_ptr<SaveFileCommand> saveFileCommand;
    std::shared_ptr<LightContrastCommand> lightContrastCommand;
    std::shared_ptr<ToGrayCommand> toGrayCommand;
    std::shared_ptr<ToBinaryCommand> toBinaryCommand;
    std::shared_ptr<DetectEdgeCommand> detectEdgeCommand;
    std::shared_ptr<GrayEqualizeHistCommand> grayEqualizeHistCommand;
    std::shared_ptr<ColorEqualizeHistCommand> colorEqualizeHistCommand;
    std::shared_ptr<LaplaceCommand> laplaceCommand;
    std::shared_ptr<LogEnhanceCommand> logEnhanceCommand;
    std::shared_ptr<GammaCorrectCommand> gammaCorrectCommand;
    std::shared_ptr<AddGaussNoiseCommand> addGaussNoiseCommand;
    std::shared_ptr<AddSaltNoiseCommand> addSaltNoiseCommand;
    std::shared_ptr<ImageSegmentationCommand> imageSegmentationCommand;
    std::shared_ptr<QImage> qImage;
    std::shared_ptr<Notification> notification;
    std::shared_ptr<UpdateDataNotification> updateNotification;
public:
    ViewModel();
    ~ViewModel();
    void setModel(std::shared_ptr<Model> model_ptr);
    std::shared_ptr<Command> getOpenFileCommand();
    std::shared_ptr<Command> getSaveFileCommand();
    std::shared_ptr<Command> getLightContrastCommand();
    void openImage(const std::string &file_name);
    void saveImage(const std::string &file_name);
    void changeImageLightContrast(int light, int contrast);
    std::shared_ptr<Command> getToGrayCommand();
    std::shared_ptr<Command> getToBinaryCommand();
    std::shared_ptr<Command> getDetectEdgeCommand();
    std::shared_ptr<Command> getGrayEqualizeHistCommand();
    std::shared_ptr<Command> getColorEqualizeHistCommand();
    std::shared_ptr<Command> getLaplaceCommand();
    std::shared_ptr<Command> getLogEnhanceCommand();
    std::shared_ptr<Command> getGammaCorrectCommand();
    std::shared_ptr<Command> getAddGaussNoiseCommand();
    std::shared_ptr<Command> getAddSaltNoiseCommand();
    std::shared_ptr<Command> getImageSegmentationCommand();
    void toGray();
    void toBinary(int& threshold);
    void detectEdge(int& threshold);
    void grayEqualizeHist();
    void colorEqualizeHist();
    void laplace();
    void logEnhance();
    void gammaCorrect(float& fGamma);
    void addGaussNoise();
    void addSaltNoise(int& n);
    void imageSegmentation(int& threshold);
    std::shared_ptr<QImage> getQImage();
    void setUpdateNotification(std::shared_ptr<Notification> notification);
    void notify();
};
