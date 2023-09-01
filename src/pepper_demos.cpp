#include <ros/ros.h>
#include <ros/package.h>

#include "pepper_demo_lib/Task.h"
#include "pepper_demo_lib/PepperRobot.h"
#include "pepper_demo_lib/Parameters.h"

#include "pepper_demos/Macarena.h"

#include <chrono>
#include <iostream>

Task createTaskInit()
{
  Task task;
  task.push_back(createAction({{ 1.242437720298767, 0.036568351089954376, -1.1184180974960327, -0.5266309380531311, -1.0351097583770752 }},
                              {{ 1.3179131746292114, -0.03515475615859032, 1.3730974197387695, 0.6137155294418335, 0.8069871068000793 }}, 2));
  //task.push_back(createAction(head_front));

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

  params.set(argc, argv);
  params.display();

  bool is_running = true;
  std::thread spin_thread(spinThread,&is_running);
  
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

  is_running = false;
  spin_thread.join();

  return 0;
}
