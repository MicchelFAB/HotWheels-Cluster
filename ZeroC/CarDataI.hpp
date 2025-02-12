/*!
 * @file CarDataI.hpp
 * @brief File containing the CarDataI class.
 * @version 0.1
 * @date 2025-02-12
 * @details This file contains the declaration of the CarDataI class, which
 * is responsible for handling the car data.
 * @author Félix LE BIHAN (@Fle-bihh)
 * @author Tiago Pereira (@t-pereira06)
 * @author Ricardo Melo (@reomelo)
 * @author Michel Batista (@MicchelFAB)
 *
 * @copyright Copyright (c) 2025
 */

#ifndef CAR_DATA_I_HPP
#define CAR_DATA_I_HPP

#include <Ice/Ice.h>
#include <mutex>
#include <thread>
#include <iostream>
#include <QObject>
#include "Joystick.h" // Generated by slice2cpp

/*!
 * @brief Namespace for the car data
 * @namespace Data
 */
namespace Data
{

	/*!
	 * @brief Class for the car data
	 * @class CarDataI
	 */
	class CarDataI : public QObject, public CarData
	{
		Q_OBJECT
	private:
		bool joystick_enable;
		double car_temperature;

		std::mutex joystick_mutex;
		std::mutex temperature_mutex;
		std::thread serverThread;
		Ice::CommunicatorPtr communicator;

	public:
		explicit CarDataI(QObject *parent = nullptr);
		~CarDataI();

		void setJoystickValue(bool newValue, const Ice::Current &) override;
		bool getJoystickValue(const Ice::Current &) override;

		void setCarTemperatureValue(double newValue, const Ice::Current &) override;
		double getCarTemperatureValue(const Ice::Current &) override;

		void runServer(int argc, char **argv);
	};

} // namespace Data

#endif
