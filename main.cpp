#include <ctime>
#include <iostream>
using namespace std;
#include "ConnectionPool.h"

int main()
{

    clock_t begin =clock();
    //ConnectionPool *cp = ConnectionPool::getConnectionPool();
		 /*	Connection conn;
			char sql[1024] = { 0 };
			 sprintf(sql, "insert into dept(dname,loc,deptno) values('%s','%s',%d)",
                  "zwq", "China", 18);   
			conn.connect("127.0.0.1", 3306, "root", "", "test1");
			conn.update(sql);*/   
        
    thread t1([](){
        
    ConnectionPool *cp = ConnectionPool::getConnectionPool();
		for (int i = 0; i < 1250; ++i)
		{
			char sql[1024] = { 0 };
			sprintf(sql, "insert into dept(dname,loc,deptno) values('%s','%s',%d)",
			 	"zhang san", "zwq", 18);
		
		shared_ptr<Connection> sp = cp->getConnection();
            sp->update(sql);
        }

              });

    thread t2([](){

    ConnectionPool *cp = ConnectionPool::getConnectionPool();

    
		for (int i = 0; i < 1250; ++i)
		{
			char sql[1024] = { 0 };
			sprintf(sql, "insert into dept(dname,loc,deptno) values('%s','%s',%d)",
			 	"zhang san", "zwq", 18);
		
		shared_ptr<Connection> sp = cp->getConnection();
            sp->update(sql);
        }
              });
                
    thread t3([](){

    ConnectionPool *cp = ConnectionPool::getConnectionPool();
		for (int i = 0; i < 1250; ++i)
		{
			char sql[1024] = { 0 };
			sprintf(sql, "insert into dept(dname,loc,deptno) values('%s','%s',%d)",
			 	"zhang san", "zwq", 18);
			
		shared_ptr<Connection> sp = cp->getConnection();
            sp->update(sql);
        
            }
              });

    thread t4([](){

    ConnectionPool *cp = ConnectionPool::getConnectionPool();
		for (int i = 0; i < 1250; ++i)
		{
			char sql[1024] = { 0 };
			sprintf(sql, "insert into dept(dname,loc,deptno) values('%s','%s',%d)",
			 	"zhang san", "zwq", 18);
		    
		shared_ptr<Connection> sp = cp->getConnection();
            sp->update(sql);
        }
              });

    t1.join(); 
    t2.join();
    t3.join();
    t4.join();
    clock_t end=clock();

        cout<<(end-begin)<<"ms"<<endl;
#if 0
		for (int i = 0; i < 1250; ++i)
		{
			char sql[1024] = { 0 };
			sprintf(sql, "insert into dept(dname,loc,deptno) values('%s','%s',%d)",
			 	"zhang san", "zwq", 18);
			shared_ptr<Connection> sp = cp->getConnection();
			sp->update(sql);
        }
#endif 
        return 0;
         
}

