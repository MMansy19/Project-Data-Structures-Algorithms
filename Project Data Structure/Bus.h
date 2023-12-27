#pragma once
#include"UI.h"
#include"Passenger.h"
#include "fifoqueue.h"

class Bus
{
private:
	Passenger** passenger_arr;	
	UI printer;
	int number;
	static int TimeBetweenStations;
    int BC;				   // bus capacity (max # of passengers can a bus carry)
	static int max_trips;  // max trips and then the bus must be unavailable for maintenance
	int curr_trips;		   // # trips after last maintenance
	int num_of_passengers; // # current passengers in the bus
	bool direction;		   // true = forward  false = backward
	int station;		   // station number [0,11]
	char bus_type;		   // mixed= M & wheel-chair= W
	int EstimatedTimeOfArrival;   //time to reach the next station
	bool InStation;               //if the bus is instation or not
	bool doneemptying;
	bool door;
	bool offhours;
	int busytime;
	float utilization;
	int checkup_time;

public:
	Bus(int capacity = 100, int s = 0, char type = 'M', int num=0);

	~Bus();
	
	void setemptying(bool);

	bool isdoneemptying();

	void display();

	void upgrade_trips();

	int get_station();
	
	void set_station(int s);

	void set_direction(bool d);

	void upgrade_station(int size, int time);
	
	int get_passengers();
	
	void setutilization();

	float getutilization();

	void set_passengers(int p);
	
	bool is_full();
	
	bool is_available();
	
	bool is_mixed_bus();

	bool isempty();

	bool maintenance_time(); // check if a bus need maintenance or not

	bool maintenance_done(int time); // check if maintenance duration finished or not


	bool exit_passenger(fifoqueue<Passenger*> &finished_array, int permin, int curr_time);

	void remove(int index);

	bool enter_passenger(Passenger* p, int curr_time);

	void setArriveTime(int);

	int getArriveTime();

	void setInStation(bool);

	void plusbusytime();

	int getbusytime();

	bool IsInStation();

	bool getDirection();

	bool getBusType();

	void setoffhoursmode(int);

	bool getoffhoursmode();

	int getTimeBetweenStations();


	static bool SetTimeBetweenStations(int);

	static bool SetMaxStations(int);

}; 