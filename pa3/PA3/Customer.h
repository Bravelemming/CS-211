#ifndef CUSTOMER_H
#define CUSTOMER_H


class Customer
{
private:
	int customer_id = -1;
	int arrival_time;
	int service_time = -1;
	int departure_time = -1;
	int id_counter =-1;


public:


	int getTotalWaitTime() {

		return (departure_time - arrival_time);
	}

	int get_arrival_time() {
		return arrival_time;
	}

	void set_arrival_time(int value) {
		arrival_time = value;
	}

	int get_service_time() {
		return service_time;
	}

	void set_service_time(int value) {
		service_time = value;
	}

	int get_customer_id() {
		return customer_id;
	}

	void set_customer_id(int value) {
		customer_id = value;
	}

	int get_departure_time() {
		return departure_time;
	}

	void set_departure_time(int value) {
		departure_time = value;
	}

	int get_id_counter() {
		return id_counter;
	}

	void set_id_counter(int value) {
		id_counter = value;
	}

};
#endif