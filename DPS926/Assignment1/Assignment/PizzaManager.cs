using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;

namespace Assignment
{
    public class PizzaManager
    {
        public ObservableCollection<Pizza> allPizzasManager = new ObservableCollection<Pizza>();
        double total_;
        int quantity_;
        string time_;

        public string time {
            get { return time_; }
            set { time_ = value; }
        }

        public double total {
            get { return total_; }
            set { total_ = value; }
        }

        public int quantity {
            get { return quantity_; }
            set { quantity_ = value; }
        }
        public PizzaManager() { }

        public void addPizza(Pizza mPizza, double mTotal, int mQuantity)
        {
            allPizzasManager.Add(mPizza);
            total_ = mTotal;
            quantity_ = mQuantity;
            time_ = DateTime.Now.ToString("yyyy/mm/dd ':' HH':'mm");
        }

        public void reset() {
            allPizzasManager.Clear();
            total_ = 0;
        }

        public void deletePizza(Pizza mPizza) {
            total_ -= mPizza.price;
            quantity_ -= mPizza.quantity;
            allPizzasManager.Remove(mPizza);
        }
    }
}
