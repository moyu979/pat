#include<iostream>
#include<queue>
#include<stack>
#include<limits.h>
#include<iomanip>
#include<algorithm>
using namespace std;
int charge[24];
struct Log
{
	string name;
	string time;
	string status;
};
struct aPhone {
	string startTime;
	string endTime;
	int minute=0;
	float charge=0;
};
struct AUser {
	string name=" ";
	char month[2] = {0,0};
	vector<aPhone> timepair;
	float charge=0;
};
void sort(vector<Log>& a) {
	int l = a.size();
	for (int i = 0; i < l; i++) {
		for (int j = i + 1; j < l; j++) {
			if (a[i].name > a[j].name) {
				Log t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
			else if (a[i].name == a[j].name && a[i].time > a[j].time) {
				Log t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}

int main() {
	vector<Log> input;

	int logNum;
	for (int i = 0; i < 24; i++) {
		cin >> charge[i];
	}
	cin >> logNum;
	for (int i = 0; i < logNum; i++) {
		Log s;
		cin >> s.name >> s.time >> s.status;
		input.push_back(s);
	}

	sort(input);
	//cout << endl;
	//for(auto s:input) {
	//	cout << s.name << s.time << s.status << endl;
	//}
	//cout << endl;

	AUser* a=new AUser;
	string time = "";
	bool nowstatu = false;
	int i = 0;
	while (i < logNum) {
		/*string month = "";
		month+=input[i].time[0] + input[i].time[1];*/
		if (input[i].name == a->name) {
			//cout << "ccc" << endl;
			if (!nowstatu) {
				if (input[i].status == "on-line") {
					time = input[i].time;
					nowstatu = true;
				}
			}
			else {
				if (input[i].status == "on-line") {
					time = input[i].time;
					nowstatu = true;
				}
				else if (nowstatu) {
					aPhone aphone;
					aphone.startTime = time;
					aphone.endTime = input[i].time;

					int startDay = (time[3] - '0') * 10 + (time[4] - '0');
					int startHour = (time[6] - '0') * 10 + (time[7] - '0');
					int startMinute = (time[9] - '0') * 10 + (time[10] - '0');
					int endDay = (input[i].time[3] - '0') * 10 + (input[i].time[4] - '0');
					int endHour = (input[i].time[6] - '0') * 10 + (input[i].time[7] - '0');
					int endMinute = (input[i].time[9] - '0') * 10 + (input[i].time[10] - '0');

					aphone.minute = (endDay * 24 * 60 + endHour * 60 + endMinute) - (startDay * 24 * 60 + startHour * 60 + startMinute);
					float bill = 0;

					if (startDay == endDay && startHour == endHour) {
						bill += (endMinute - startMinute) * charge[startHour];
					}
					else if (startDay == endDay) {
						if (startMinute != 0) {
							bill += (60 - startMinute) * charge[startHour];
							startMinute = 0;
							startHour++;
						}
						while (startHour != endHour) {
							bill += charge[startHour] * 60;
							startHour++;
						}
						if (endMinute != 0) {
							bill += endMinute * charge[endHour];
						}
					}
					else {
						if (startMinute != 0) {
							bill += (60 - startMinute) * charge[startHour];
							startHour++;
						}
						while (startHour != 24) {
							bill += charge[startHour] * 60;
							startHour++;
						}
						startDay++;
						while (startDay != endDay) {
							for (int k = 0; k < 24; k++) {
								bill += charge[k] * 60;
							}
							startDay++;
						}
						startHour = 0; startMinute = 0;
						while (startHour != endHour) {
							bill += charge[startHour] * 60;
							startHour++;
						}
						bill += endMinute * charge[endHour];
					}
					aphone.charge = bill/100;
					a->timepair.push_back(aphone);
					a->charge += bill/100;
					nowstatu = false;
				}
			}
		}
		else {
			if (a->charge != 0) {
				cout << a->name << " " << a->month[0]<<a->month[1] << endl;

				for (auto ss : a->timepair) {
					cout << ss.startTime.substr(3) << " " << ss.endTime.substr(3) << " " << ss.minute;
					printf(" $%0.2f\n", ss.charge);
				}
				printf("Total amount: $%0.2f\n", a->charge);
			}
			a = new AUser;
			a->name = input[i].name;
			a->month[0] = input[i].time[0];
			a->month[1] = input[i].time[1];
			a->charge = 0;
			nowstatu = false;
			i--;
		}
		i++;
		//cout << i << "ddd" << endl;
	}
	if (a->charge != 0) {
		cout << a->name << " " << a->month[0] << a->month[1] << endl;

		for (auto ss : a->timepair) {
			cout << ss.startTime.substr(3) << " " << ss.endTime.substr(3) << " " << ss.minute;
			printf(" $%0.2f\n", ss.charge);
		}
		printf("Total amount: $%0.2f\n", a->charge);
	}
	return 0;
}
