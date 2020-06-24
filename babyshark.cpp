#include <chrono>
#include <ctime>
#include <functional>
#include <iostream>
#include <random>
#include <thread>
#include <vector>

class Bullshit
{
  enum State
  {
    Baby = 0,
    Shark,
    Doo,
    Daddy,
    Grandpa,
    Grandma,
    Mommy,
    Safe,
    Run,
    Lets,
    Its,
    At,
    Away,
    Go,
    The,
    Last,
    Hunt,
    End,
  };

  State state = Baby;

  std::vector<std::string> sharktable = {
    "Baby",  "Shark", "Doo", "Daddy", "Grandpa", "Grandma",
    "Mommy", "Safe",  "Run", "Lets",  "Its",     "At",
    "Away",  "Go",    "The", "Last",  "Hunt",    "End",
  };
  std::vector<std::vector<State>> statetable = {
    { Shark },                                                     // Baby
    { Daddy, Grandpa, Grandma, Mommy, Doo, Lets },                 // Shark
    { Daddy, Grandpa, Grandma, Mommy, Safe, Run, Lets, Its, Doo }, // Doo
    { Shark },                                                     // Daddy
    { Shark },                                                     // Grandpa
    { Shark },                                                     // Grandma
    { Shark },                                                     // Mommy
    { At },                                                        // Safe
    { Away },                                                      // Run
    { Go },                                                        // Lets
    { The },                                                       // Its
    { Last },                                                      // At
    { Doo },                                                       // Away
    { Hunt },                                                      // Go
    { End },                                                       // The
    { Doo },                                                       // Last
    { Doo },                                                       // Hunt
    { Doo },                                                       // End
  };

  void update_state()
  {
    size_t range = statetable[state].size();
    size_t choice = static_cast<size_t>(std::rand()) % range;
    state = statetable[state][choice];
  }

  void execute_state()
  {
    std::cout << sharktable[state] << ' ' << std::flush;
    std::string command =
      "aplay audio/" + sharktable[state] + ".wav 2>/dev/null >/dev/null";
    system(command.c_str());
  }

public:
  Bullshit() { srand(time(NULL)); }
  void step()
  {
    execute_state();
    update_state();
  }
};

int
main(void)
{
  using namespace std::chrono_literals;
  Bullshit baby_shark_machine;
  char c;
  for (int i = 0; i < 100; i++) {
    baby_shark_machine.step();
  }
  return {};
}
