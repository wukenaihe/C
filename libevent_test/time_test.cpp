//#include <event2/event.h>  
//#include <event2/util.h>  
//#include <iostream>  
//#include <stdlib.h>
//#include <stdio.h>  
//
//using namespace std;  
//
//struct EventTimerParam  
//{  
//	struct timeval tv;  
//	void *ctx;  
//	void *evt;//event  
//};  
//
//void libevent_tick_event_cb(evutil_socket_t fd, short events, void *ctx)  
//{  
//	printf("function1 is called\n");  
//	EventTimerParam *pParam = (EventTimerParam*)ctx;  
//	pParam->tv.tv_sec = 1;  
//	evtimer_add((struct event*)pParam->evt, &pParam->tv);  
//}  
//
//int main()  
//{  
//	//初始化一个Reactor
//	struct event_base *base_;  
//	base_ = event_base_new();  
//	if(!base_)    
//	{  
//		cout<<"Can't open event base"<<endl;  
//		return 1;  
//	}  
//
//	EventTimerParam *pTimerParam = new EventTimerParam();
//	//初始化事件Event,相当于初始化event handle
//	struct event *ev = evtimer_new(base_, libevent_tick_event_cb, pTimerParam);  
//	pTimerParam->evt = ev;  
//	pTimerParam->ctx = NULL;  
//	pTimerParam->tv.tv_sec = 1;  
//
//	//添加事件
//	evtimer_add(ev, &pTimerParam->tv);  
//
//	int err = event_base_dispatch(base_);     
//	//int err = event_base_loop(base_, EVLOOP_ONCE);  
//
//	//  int err = event_base_loop(base_, EVLOOP_NONBLOCK);  
//	cout<<"err = "<< err <<endl;  
//	return 0;  
//}  