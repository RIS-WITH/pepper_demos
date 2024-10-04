#ifndef PEPPER_DEMOS_SYNCHROMACARENA_H
#define PEPPER_DEMOS_SYNCHROMACARENA_H

#include "pepper_demo_lib/PepperRobot.h"
#include "pepper_demo_lib/Task.h"

Task createDanceSynchroTask(const std::string& synchro_ip)
{
  Task task;

  task.push_back(createActionWaitSynchro(synchro_ip));

  task.push_back(createActionTurn(-25));

  task.push_back(createActionMove(1, -1.1));

  task.push_back(createActionResetBody());

  task.push_back(createActionSynchro(synchro_ip));

  task.push_back(createActionDelay(6300));

  task.push_back(createActionSpeakAnim("Bonjour, je m'appel paipeur"));

  task.push_back(createAction({
                                {1.242437720298767, 0.036568351089954376, -1.1184180974960327, -0.5266309380531311, -1.0351097583770752}
  },
                              {{1.3179131746292114, -0.03515475615859032, 1.3730974197387695, 0.6137155294418335, 0.8069871068000793}}, 1.2));

  // task.push_back(createActionLaunchSynchro(synchro_ip));

  task.push_back(createActionSynchro(synchro_ip));

  task.push_back(createActionSpeakAnim("Nous sommes vraiment trais heureux que vous soyez ici. Vous aller adorer ce que vous allez voire."));

  task.push_back(createAction({
                                {1.242437720298767, 0.036568351089954376, -1.1184180974960327, -0.5266309380531311, -1.0351097583770752}
  },
                              {{1.3179131746292114, -0.03515475615859032, 1.3730974197387695, 0.6137155294418335, 0.8069871068000793}}, 1.2));

  // task.push_back(createActionLaunchSynchro(synchro_ip));

  task.push_back(createActionSynchro(synchro_ip));

  task.push_back(createActionDelay(500));

  task.push_back(createAction({
                                {0,        0.086960, 0,        0,        0       }, //  210
                                {0,        0.086960, 0,        0,        0       },
                                {0,        0.086960, -1.06238, 0,        -1.80083}, // 230
                                {0,        0.086960, -1.06238, 0,        -1.80083},
                                {0.14515,  0.08690,  0.30760,  -0.50684, -1.80083}, // 250
                                {0.14515,  0.08690,  0.13615,  -1.41386, -1.80083},
                                {0.14515,  0.08690,  0.13615,  -1.41386, -1.80083}, // 270
                                {-1.23085, 0.57967,  0.13615,  -1.50516, -1.64885},
                                {-1.23085, 0.57967,  0.13615,  -1.50516, -1.64885}, // 290
                                {0.67472,  0.18804,  0.13615,  -1.22348, -0.45565},
                                {0.67472,  0.18804,  0.13615,  -1.22348, -0.45565}, // 310
                                {1.12046,  0.59808,  0.19638,  -1.22348, -1.34629},
                                {-0.03584, 0.12881,  -1.46250, -1.22348, -1.34629}
  },

                              {{0, 0, 0, 0, 0}, // 210
                               {0, 0, 1.79769, 0, 0.93269},
                               {0, 0, 1.79769, 0, 0.93269}, // 230
                               {-0.23236, 0, -0.07572, 1.45465, 0.93269},
                               {-0.23236, 0, -0.07572, 1.45465, 0.93269}, // 250
                               {-0.23236, 0, -0.07572, 1.45465, 0.93269},
                               {-1.21913, -0.61377, -0.07572, 1.57294, 2.16371}, // 270
                               {-1.21913, -0.61377, -0.07572, 1.57294, 2.16371},
                               {0.93036, -0.10181, -0.19837, 0.91316, 0.80708}, // 290
                               {0.93036, -0.10181, -0.19837, 0.91316, 0.80708},
                               {1.13323, -0.69311, -0.19837, 1.33894, 2.03192}, // 310
                               {1.13323, -0.69311, -0.19837, 1.33894, 2.03192},
                               {0.06366, -0.055, 1.47557, 1.33894, 2.03192}},
                              1.55));

  task.push_back(createActionSpeak("Hey makaraina !"));

  task.push_back(createAction({
                                {1.10622,           0.12881,              -1.46250,            -1.22348,            -1.34629           },
                                {1.242437720298767, 0.036568351089954376, -1.1184180974960327, -0.5266309380531311, -1.0351097583770752}
  },

                              {{1.14574, -0.055, 1.47557, 1.33894, 2.03192}, {1.3179131746292114, -0.03515475615859032, 1.3730974197387695, 0.6137155294418335, 0.8069871068000793}}));

  task.push_back(createActionDelay(2000));

  task.push_back(createActionSynchro(synchro_ip));
  task.push_back(createActionDelay(5000));

  task.push_back(createActionSpeakAnim("Pai pai paipeur"));

  task.push_back(createActionDelay(19000));

  task.push_back(createActionSpeakAnim("Tout ce que vous venez de voire n'est qu'un script. Il est maintenent temps de voir ce qu'il y a derriaire la machine."));

  task.push_back(createAction({
                                {1.242437720298767, 0.036568351089954376, -1.1184180974960327, -0.5266309380531311, -1.0351097583770752}
  },
                              {{1.3179131746292114, -0.03515475615859032, 1.3730974197387695, 0.6137155294418335, 0.8069871068000793}}, 1.2));

  task.push_back(createActionSynchro(synchro_ip));

  task.push_back(createAction(head_front));

  task.push_back(createActionTurn(35));

  task.push_back(createActionMoveFront(-0.8));

  task.push_back(createActionTurn(-35));

  task.push_back(createActionResetBody());

  return task;
}

#endif // PEPPER_DEMOS_SYNCHROMACARENA_H
