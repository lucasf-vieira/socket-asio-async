#include "drink_store.hpp"

enum class DrinkStore::Drink
{
   Beer = 0,
   Water,
   Soda
};

DrinkStore::DrinkStore()
{
   Parser mParser;
   mDrinksArray = mParser.initialize_drinks();
}

bool DrinkStore::is_drink_available(Drink fDrink, int DrinkQuantity)
{
   if (mDrinksArray.at(static_cast<int>(fDrink)) >= DrinkQuantity)
   {
      return true;
   }
   else
   {
      return false;
   }
}

void DrinkStore::send_drink(Drink fDrink, int DrinkQuantity)
{
   mDrinksArray.at(static_cast<int>(fDrink)) -= DrinkQuantity;
}

std::string DrinkStore::check_drink_list_availability(std::array<int, 3> RequestedDrinksArray)
{
   std::string ClientMessage_HasDrink;
   std::string ClientMessage_HasNotDrink;

   bool HasDrink = false;
   bool HasNotDrink = false;

   for (size_t i = 0; i < RequestedDrinksArray.size(); i++)
   {
      if (is_drink_available(Drink(i), RequestedDrinksArray.at(i)) && RequestedDrinksArray.at(i) > 0)
      {
         if (!HasDrink)
         {
            ClientMessage_HasDrink.append("Voce comprou ");
         }
         HasDrink = true;

         ClientMessage_HasDrink.append(std::to_string(RequestedDrinksArray.at(i)));
         ClientMessage_HasDrink.append(" ");
         ClientMessage_HasDrink.append(get_drink_name(Drink(i)));
         ClientMessage_HasDrink.append("; ");

         send_drink(Drink(i), RequestedDrinksArray.at(i));
      }
      else if (RequestedDrinksArray.at(i) > 0)
      {
         if (!HasNotDrink)
         {
            ClientMessage_HasNotDrink.append("\nA loja nao pode entregar: ");
         }
         HasNotDrink = true;

         ClientMessage_HasNotDrink.append(std::to_string(RequestedDrinksArray.at(i)));
         ClientMessage_HasNotDrink.append(" ");
         ClientMessage_HasNotDrink.append(get_drink_name(Drink(i)));
         ClientMessage_HasNotDrink.append("; ");
      }
   }
   if(HasNotDrink == false && HasDrink == false)
   {
      return std::string("Voce nao comprou nada!");
   }

   ClientMessage_HasDrink.append(ClientMessage_HasNotDrink);
   std::string ClientMessage = ClientMessage_HasDrink;

   return ClientMessage;
}

std::string DrinkStore::get_drink_name(Drink fDrink) const
{
   switch (fDrink)
   {
   case Drink::Beer:
      return std::string("cervejas");

   case Drink::Water:
      return std::string("aguas");

   case Drink::Soda:
      return std::string("refrigerantes");

   default:
      return std::string("bebidas nao identificadas");
   }
}

std::ostream &operator<<(std::ostream &output, const DrinkStore &Store)
{
   output << "Quantidade de bebidas restantes na loja:" << std::endl;
   output << "Cervejas      : " << Store.mDrinksArray.at(0) << std::endl;
   output << "Aguas         : " << Store.mDrinksArray.at(1) << std::endl;
   output << "Refrigerantes : " << Store.mDrinksArray.at(2) << std::endl;

   return output;
}