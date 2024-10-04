#include <chrono>
#include <iostream>
#include <ros/package.h>
#include <ros/ros.h>

#include "pepper_demo_lib/Parameters.h"
#include "pepper_demo_lib/PepperRobot.h"
#include "pepper_demo_lib/Task.h"
#include "pepper_demos/Macarena.h"
#include "pepper_demos/MacarenaSynchro.h"
#include "pepper_demos/TransitionPr2.h"

Task createTaskInit()
{
  Task task;
  task.push_back(createAction({
                                {1.242437720298767, 0.036568351089954376, -1.1184180974960327, -0.5266309380531311, -1.0351097583770752}
  },
                              {{1.3179131746292114, -0.03515475615859032, 1.3730974197387695, 0.6137155294418335, 0.8069871068000793}}, 2));
  // task.push_back(createAction(head_front));

  return task;
}

void spinThread(bool* is_running)
{
  while((*is_running == true) && (ros::ok()))
  {
    ros::spinOnce();
    usleep(100);
  }
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "pepper_demos");

  Parameters params;
  params.insert(Parameter("task", {"-t", "--task"}));
  params.insert(Parameter("language", {"-l", "--language"}, {"fr"}));
  params.insert(Parameter("ip", {"-i", "--ip"}, {""}));

  params.set(argc, argv);
  params.display();

  bool is_running = true;
  std::thread spin_thread(spinThread, &is_running);

  PepperRobot robot(true);

  if(params.at("task").getFirst() == "init")
  {
    Task init_task = createTaskInit();
    executeTask(&robot, init_task);
  }
  else if(params.at("task").getFirst() == "dance")
  {
    std::cout << "start dance !" << std::endl;
    Task task = createDanceTask();
    executeTask(&robot, task);
  }
  else if(params.at("task").getFirst() == "transition_pr2")
  {
    std::cout << "start transition" << std::endl;
    std::string synchro_ip = params.at("ip").getFirst();
    Task task = createTransitionPr2Task(synchro_ip);
    executeTask(&robot, task);
  }
  else if(params.at("task").getFirst() == "reset_transition_pr2")
  {
    std::cout << "start transition" << std::endl;
    std::string synchro_ip = params.at("ip").getFirst();
    Task task = createResetTransitionPr2Task(synchro_ip);
    executeTask(&robot, task);
  }
  else if(params.at("task").getFirst() == "1")
  {
    std::cout << "start 1" << std::endl;
    std::string synchro_ip = params.at("ip").getFirst();
    Task task = createResetTestTask(synchro_ip);
    executeTask(&robot, task);
  }
  else if(params.at("task").getFirst() == "2")
  {
    std::cout << "start 2" << std::endl;
    std::string synchro_ip = params.at("ip").getFirst();
    Task task = createTestTask(synchro_ip);
    executeTask(&robot, task);
  }
  else if(params.at("task").getFirst() == "synchro")
  {
    std::string synchro_ip = params.at("ip").getFirst();
    if(synchro_ip == "")
    {
      std::cout << "The synchronized dance requires you to provide the synchro ip using the -i or --ip parameter." << std::endl;
      std::cout << "Dance will be performed without considering any synchronization" << std::endl;
    }
    std::cout << "start synchro dance !" << std::endl;
    Task task = createDanceSynchroTask(synchro_ip);
    executeTask(&robot, task);
  }
  else
    std::cout << "The requested task is unknown" << std::endl;

  is_running = false;
  spin_thread.join();

  return 0;
}
