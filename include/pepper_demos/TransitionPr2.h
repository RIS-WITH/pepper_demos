#ifndef PEPPER_DEMOS_TRANSITIONPR2_H
#define PEPPER_DEMOS_TRANSITIONPR2_H

#include "pepper_demo_lib/PepperRobot.h"
#include "pepper_demo_lib/Task.h"

Task createTransitionPr2Task(const std::string& syncho_ip)
{
  Task task;

  task.push_back(createActionWaitSynchro(syncho_ip));

  task.push_back(createActionTurn(35));

  task.push_back(createActionMoveFront(-1));

  task.push_back(createActionTurn(20));

  task.push_back(createActionResetBody());

  return task;
}

Task createResetTransitionPr2Task(const std::string& syncho_ip)
{
  Task task;

  task.push_back(createActionWaitSynchro(syncho_ip));

  task.push_back(createActionTurn(-20));

  task.push_back(createActionMoveFront(1));

  task.push_back(createActionTurn(-35));

  task.push_back(createActionResetBody());

  return task;
}

Task createTestTask(const std::string& syncho_ip) // 2
{
  Task task;

  task.push_back(createActionWaitSynchro(syncho_ip));

  task.push_back(createActionTurn(-25));

  task.push_back(createActionMove(1, -1.1));

  task.push_back(createActionTurn(35));

  task.push_back(createActionMoveFront(-0.8));

  task.push_back(createActionTurn(-35));

  return task;
}

Task createResetTestTask(const std::string& syncho_ip) // 1
{
  Task task;

  task.push_back(createActionWaitSynchro(syncho_ip));

  task.push_back(createActionTurn(35));

  task.push_back(createActionMoveFront(0.8));

  task.push_back(createActionTurn(-35));

  task.push_back(createActionMove(-1, 1.1));

  task.push_back(createActionTurn(25));

  return task;
}

#endif // PEPPER_DEMOS_TRANSITIONPR2_H