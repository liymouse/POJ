#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

#define NUM 100
enum {
	ENTRY = 0,
	STAY_IN_ROOM,
	STAY_IN_ELEVATOR,
	TRANSFER_FROM_ROOM_TO_ELEVATOR,
	TRANSFER_FROM_ROOM_TO_ROOM,
	TRANSFER_FROM_ELEVATOR_TO_ROOM,
	WAITING_ELEVATOR,
	WAITING_ROOM,
	EXIT,
	STATE_NUM
};

typedef struct
{
	int state;
	int starttime;
	int endtime;
	int currentfloor;
	int currentroom;
	int visitlist_num;
	int visitlist_floor[NUM];
	int visitlist_room[NUM];
	int visitlist_stay[NUM];
	int visitid;
	int waiting_time;
	vector<string> record;
}Agent;

Agent a[26];
int room[11][11] = {0};
int elevator[11] = {0};

void getStr(char *str , int start , int end , int state , int floor1 , int room1 , int floor2 , int room2)
{
	int sh = start/360;
	int sm = (start%360) / 60;
	int ss = start%60;
	int eh = end/360;
	int em = (end%360) / 60;
	int es = end%60;
	char sen[1024] = "";
	switch (state)
	{
	case ENTRY:
		sprintf(sen , "Entry");
		break;
	case STAY_IN_ROOM:
		sprintf(sen , "Stay in room %02d%02d" , floor1 , room1);
		break;
	case STAY_IN_ELEVATOR:
		sprintf(sen , "Stay in elevator");
		break;
	case TRANSFER_FROM_ROOM_TO_ELEVATOR:
		sprintf(sen , "Transfer from room %02d%02d to elevator" , floor1 , room1);
		break;
	case TRANSFER_FROM_ROOM_TO_ROOM:
		sprintf(sen , "Transfer from room %02d%02d to room %02d%02d" , floor1 , room1 , floor2 , room2);
		break;
	case TRANSFER_FROM_ELEVATOR_TO_ROOM:
		sprintf(sen , "Transfer from elevator to room %02d%02d" , floor1 , room1);
		break;
	case WAITING_ELEVATOR:
		sprintf(sen , "Waiting in elevator queue");
		break;
	case WAITING_ROOM:
		sprintf(sen , "Waiting in front of room %02d%02d" , floor1 , room1);
		break;
	case EXIT:
	default:
		sprintf(sen , "Exit");
		break;
	}
	sprintf(str , "%02d:%02d:%02d %02d:%02d:%02d %s" , sh , sm , ss , eh , em , es , sen);
}



void active(Agent a[] , int i)
{
	char str[1024];
	int vid = a[i].visitid;
	int nextfloor = a[i].visitlist_floor[vid];
	int nextroom  = a[i].visitlist_room [vid];
	
	switch (a[i].state)
	{
	case ENTRY:
		a[i].endtime = a[i].starttime + 30;
		getStr(str , a[i].starttime , a[i].endtime , a[i].state , a[i].currentfloor , a[i].currentroom , nextfloor , nextroom);
		gotonextroom(&a[i]);
		break;
	case STAY_IN_ROOM:
		room[a[i].currentfloor][a[i].currentroom] = 0;
		a[i].endtime = a[i].starttime + a[i].visitlist_stay[vid];
		getStr(str , a[i].starttime , a[i].endtime , a[i].state , a[i].currentfloor , a[i].currentroom , nextfloor , nextroom);
		a[i].visitid ++;
		gotonextroom(&a[i]);
		break;
	case STAY_IN_ELEVATOR:
		a[i].endtime = a[i].starttime + abs(a[i].currentfloor - a[i].visitlist_floor[vid]) * 30;
		a[i].currentfloor = a[i].visitlist_floor[vid];
		getStr(str , a[i].starttime , a[i].endtime , a[i].state , a[i].currentfloor , a[i].currentroom , nextfloor , nextroom);
		if (a[i].visitlist_room[vid] == -1) a[i].state = EXIT;
		else a[i].state = TRANSFER_FROM_ELEVATOR_TO_ROOM;
		break;
	case TRANSFER_FROM_ROOM_TO_ELEVATOR:
		a[i].endtime = a[i].starttime + 10;
		getStr(str , a[i].starttime , a[i].endtime , a[i].state , a[i].currentfloor , a[i].currentroom , nextfloor , nextroom);
		a[i].state = WAITING_ELEVATOR;
		a[i].waiting_time = 0;
		break;
	case TRANSFER_FROM_ROOM_TO_ROOM:
	case TRANSFER_FROM_ELEVATOR_TO_ROOM:
		a[i].endtime = a[i].starttime + 10;
		getStr(str , a[i].starttime , a[i].endtime , a[i].state , a[i].currentfloor , a[i].currentroom , nextfloor , nextroom);
		a[i].state = WAITING_ROOM;
		a[i].waiting_time = 0;
		break;
	case WAITING_ELEVATOR:
		/* wait someone */
		int has = -1;
		for (int j = i-1; j >= 0; j --)
			if (a[j].state == WAITING_ELEVATOR && a[j].currentfloor == a[i].currentfloor)
			{
				has = j; break;
			}
		if (has != -1)
		{
			a[i].endtime = a[has].starttime + 5;
			a[i].waiting_time += a[i].endtime - a[i].starttime;
			a[i].starttime = a[i].endtime;
		}
		else
		{
			if (a[i].starttime % 5 == 0)
			{
				if (a[i].waiting_time > 0)
				{
					getStr(str , a[i].starttime-a[i].waiting_time , a[i].endtime , a[i].state , a[i].currentfloor , a[i].currentroom , nextfloor , nextroom);
					a[i].record.push_back(str);
				}
				a[i].state = STAY_IN_ELEVATOR;
			}
			else
			{
				a[i].waiting_time += 5 - a[i].starttime%5;
				a[i].starttime += 5-a[i].starttime%5;
			}
		}
		has = -1;
		int wait = 5;
		for (int j = i+1; j < 26; j ++)
			if (a[j].state == WAIT_ELEVATOR && a[j].currentfloor == a[i].currentfloor)
			{
				a[j].waiting_time += (a[i].starttime+wait) - a[j].starttime;
				a[j].starttime = a[i].starttime + wait;
				wait += 5;
			}
		return;
		break;
	case WAITING_ROOM:
		if (room[nextfloor][nextroom] == 0)
		{
			room[nextfloor][nextroom] = 1;
			a[i].currentfloor = nextfloor;
			a[i].currentroom = nextroom;
			a[i].state = STAY_IN_ROOM;
			return;
		}
		else
		{

		}
		break;
	case EXIT:
		break;
	default:
		break;
	}
	a[i].record.push_back(str);
	a[i].starttime = a[i].endtime;
}

int main()
{
	char name[10];
	for (int i = 0; i < 26; i ++) a[i].state = STATE_NUM;
	while (scanf("%s" , name) == 1)
	{
		if (name[0] == '.') break;
		int i = name[0]-'A';
		a[i].state = ENTRY;

		char start[50];
		scanf("%s" , start);
		int hh = (start[0]-'0') * 10 + (start[1]-'0');
		int mm = (start[3]-'0') * 10 + (start[4]-'0');
		int ss = (start[6]-'0') * 10 + (start[7]-'0');
		a[i].starttime = hh * 360 + mm * 60 + ss;
		a[i].endtime = a[i].starttime + 30;

		char roomid[100];
		int n = 0;
		while (scanf("%s" , roomid) == 1)
		{
			if (roomid[0] == '0' && roomid[1] == 0) break;
			a[i].visitlist_floor[n] = (roomid[0]-'0') * 10 + (roomid[1]-'0');
			a[i].visitlist_room[n] = (roomid[2]-'0') * 10 + (roomid[3]-'0');
			scanf("%d" , &a[i].visitlist_stay[n]);
			n ++;
		}
		/* add reception to the last place */
		a[i].visitlist_floor[n] = 1;
		a[n].visitlist_room[n] = -1;
		a[n].visitlist_stay[n] = 0;
		n ++;
		a[i].visitlist_num = n;

		/* set current place to reception */
		a[i].currentfloor = 1;
		a[i].currentroom = -1; 
		a[i].visitid = 0;
	}
	while(1)
	{
		int done = 1;
		for (int i = 0; i < 26; i ++)
			if (a[i].state < STATE_NUM) {done = 1; break;}
		if (done) break;

		int minv = 1<<30;
		int id = 0;
		for (int i = 0; i < 26; i ++)
			if (a[i].state < STATE_NUM && a[i].starttime < minv)
			{
				id = i; minv = a[i].starttime;
			}
		active(a , id);
	}
	for (int i = 0; i < 26; i ++)
		if (a[i].record.size() > 0)
		{
			printf("%c\n" , (char)('A'+i));
			for (vector<string>::iterator j = a[i].record.begin(); j != a[i].record.end(); j ++)
			{
				printf("%s\n" , (*j).c_str());
			}
			printf("\n");
		}
	return 0;
}