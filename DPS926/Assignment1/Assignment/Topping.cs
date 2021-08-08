using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Text;

namespace Assignment
{
    public class Topping
    {
        private string topping_;
        public string topping
        {
            get { return topping_; }
            set { topping_ = value; }
        }

        public Topping(string _topping)
        {
            this.topping_ = _topping;
        }
    }

    public class ToppingManager {
        public ObservableCollection<Topping> allToppings = new ObservableCollection<Topping>();

        public ToppingManager()
        {
            allToppings.Add(new Topping("Vegetable"));
            allToppings.Add(new Topping("Meat Balls"));
            allToppings.Add(new Topping("Pepperoni"));
            allToppings.Add(new Topping("Mushrooms"));
            allToppings.Add(new Topping("Sausage"));
            allToppings.Add(new Topping("Extra Cheese"));
            allToppings.Add(new Topping("Green Peppers"));
        }
    }
}
