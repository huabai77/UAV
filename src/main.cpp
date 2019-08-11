#include "mixr/base/Object.hpp"
#include "mixr/base/edl_parser.hpp"
#include "mixr/base/Pair.hpp"
#include "mixr/base/util/system_utils.hpp"
#include "mixr/base/factory.hpp"
#include "mixr/simulation/Station.hpp"
#include "mixr/simulation/factory.hpp"
#include "mixr/models/factory.hpp"
#include "mixr/terrain/factory.hpp"

mixr::base::Object* factory(const std::string& name)
{
   mixr::base::Object* obj{mixr::simulation::factory(name)};
   if (obj == nullptr) obj = mixr::models::factory(name);
   if (obj == nullptr) obj = mixr::terrain::factory(name);
   if (obj == nullptr) obj = mixr::base::factory(name);
   return obj;
}

mixr::simulation::Station *builder(const std::string &filename)
{
   // read configuration file
   int num_errors{};
   mixr::base::Object *obj{mixr::base::edl_parser(filename, factory, &num_errors)};
   if (num_errors > 0)
   {
      std::cerr << "File: " << filename << ", number of errors: " << num_errors << std::endl;
      std::exit(EXIT_FAILURE);
   }

   // test to see if an object was created
   if (obj == nullptr)
   {
      std::cerr << "Invalid configuration file, no objects defined!" << std::endl;
      std::exit(EXIT_FAILURE);
   }

   // do we have a base::Pair, if so, point to object in Pair, not Pair itself
   const auto pair = dynamic_cast<mixr::base::Pair *>(obj);
   if (pair != nullptr)
   {
      obj = pair->object();
      obj->ref();
      pair->unref();
   }

   // try to cast to proper object, and check
   const auto station = dynamic_cast<mixr::simulation::Station *>(obj);
   if (station == nullptr)
   {
      std::cerr << "Invalid configuration file!" << std::endl;
      std::exit(EXIT_FAILURE);
   }
   return station;
}

int main(int argc, char *argv[])
{
   std::cout << "Start" << std::endl;

   // default configuration filename
   std::string configFilename = "config.edl";

   for (int i = 1; i < argc; i++)
   {
      if (std::string(argv[i]) == "-f")
      {
         configFilename = argv[++i];
      }
   }
   std::cout << configFilename << std::endl;

   mixr::simulation::Station *station{builder(configFilename)};
   // send a reset event and frame sim once
   station->event(mixr::base::Component::RESET_EVENT);
   station->tcFrame(static_cast<double>(1.0 / static_cast<double>(station->getTimeCriticalRate())));

   // create time critical thread
   station->createTimeCriticalProcess();
   // short pause to allow os to startup thread
   mixr::base::msleep(1000);

   // calc delta time for background thread
   const double dt{1.0 / static_cast<double>(10)};

   for (int i=0;i<10;i++)
   {
      // update background thread
      station->updateData(static_cast<double>(dt));
   }

   std::cout << "End" << std::endl;

   return 0;
}
