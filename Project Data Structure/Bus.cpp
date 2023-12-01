#include "Bus.h"

Bus::Bus(int capacity, int s, char type)
	: BC(capacity), station(s)
{
	passenger_arr = new Passenger * [capacity];
	finished_queue = new fifoqueue<Passenger*>();

	distance = 0;
	curr_trips = 0;
	num_of_passengers = 0;
	direction = 1;
	direction = true;
	closed = false;
	if (type == 'W')
		bus_type = 0;
	if (type == 'W' || 'w')
		bus_type = 'W';
	else
		bus_type = 1;
	bus_type = 'M';
}

Bus::~Bus()
{
	delete[] passenger_arr;
}

void Bus::display()
{
	string available = "No, not available", mixed = "No, not mixed bus";
	if (is_available())
		available = "Yes";
	if (is_mixed_bus())
		mixed = "Yes, mixed bus";

	cout << "Reading Bus Data: "<< endl
		<< "Station Number: " << get_station() << endl
		<< "Number of Passengers: " << get_passengers()<< endl
		<< "Is available?: " << available << endl
		<< "Station Number: " << mixed << endl
		<< "Station Number: " << maintenance_time() << endl;
}

bool Bus::get_door()
{
	return closed; // closed=1 , open=0
}

void Bus::set_door(bool door)
{
	closed = door; // closed=1 , open=0
}

int Bus::get_station()
{
	return station;
}

void Bus::set_station(int s)
{
	station = s;
}

void Bus::set_direction(bool d) //d=true => forward or d=false => backward
{
	direction = d;
}

void Bus::upgrade_station()
{
	if (direction == true)
		station++;
	else
		station--;

}

int Bus::get_distance()
{
	return distance;
}

void Bus::set_distance(int d)
{
	distance = d;
}


void Bus::exit_passenger()
{
	int num = get_passengers();
	for (int i = 0; i < num; i++)
	{
		if (passenger_arr[i]->GetEndStation() == station)
		{
			finished_queue->push(passenger_arr[i]);
			remove(i);
		}
	}
}

int Bus::get_passengers()
{
	return num_of_passengers;
}

void Bus::set_passengers(int p)
{
	num_of_passengers = p;
}

bool Bus::is_full()
{
	return num_of_passengers == BC;
}

bool Bus::is_available()
{
	return num_of_passengers <= BC;
}

bool Bus::is_mixed_bus()
{
	if(bus_type == 'M')
		return true;
	return false;
}

bool Bus::maintenance_time()
{
	return max_trips == curr_trips;
}

void Bus::remove(int index)
{
	if (index + 1 == num_of_passengers)
	{
		delete passenger_arr[index];
		num_of_passengers--;
		return;
	}

	for (int i = index + 1; i < num_of_passengers; i++)
	{
		passenger_arr[i] = passenger_arr[i - 1];
	}
	num_of_passengers--;
	return;
}

bool Bus::enter_passenger(Passenger* p)
{
	if (is_available())
	{
		int num = get_passengers();
		passenger_arr[num] = p;
		set_passengers(num + 1);
		return true;
	}
	return false;
}


void Bus::setArriveTime(int t)
{
	EstimatedTimeOfArrival = t;
}

int Bus::getArriveTime()
{
	return EstimatedTimeOfArrival;
}

void Bus::setInStation(bool Case)
{
	InStation = Case;
}

bool Bus::getInStation()
{
	return InStation;
}

bool Bus::getDirection()
{
	return direction;
}

bool Bus::getBusType()
{
	if (bus_type=='M')
	{
		return true;
	}
	return false;
}

bool Bus::SetTimeBetweenStations(int t)
{
	TimeBetweenStations = t;
	return true;
}

bool Bus::SetMaxStations(int s)
{
	max_trips = s;
	return false;
}


int Bus::TimeBetweenStations = 0;
int Bus:: max_trips=0;
