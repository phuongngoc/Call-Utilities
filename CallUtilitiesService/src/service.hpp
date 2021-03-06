/*
 * Copyright (c) 2013-2014 BlackBerry Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SERVICE_H_
#define SERVICE_H_

#include <src/RainbowLed.hpp>
#include <QObject>

namespace bb {
    class Application;
    namespace system {
        namespace phone {
            class Call;
            class Phone;
            class CallState;
            class CallType;
        }
    }
    namespace device {
        class Led;
        class LedColor;
        class VibrationController;
    }
}

class Service: public QObject
{
    Q_OBJECT
public:
    Service();
    virtual ~Service() {}

private slots:
    void onCallUpdated(const bb::system::phone::Call & call);
    void init();

private:
    void onIncoming();
    void onIncomingConnect();
    void onIncomingDisconnect();
    void onOutgoingConnect();
    void onOutgoingDisconnect();

    static const QString sAuthor;
    static const QString sApp;

    static const QString sIncomingDisconnectedVibrate;
    static const QString sIncomingFlashLed;
    static const QString sIncomingFlashLedColor;
    static const QString sOutgoingConnectedVibrate;
    static const QString sOutgoingDisconnectedVibrate;

    RainbowLed rainbowLed;

};

#endif /* SERVICE_H_ */
