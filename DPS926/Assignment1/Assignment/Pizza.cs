using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Text;

namespace Assignment
{
    public class Pizza
    {
        Topping topping_;
        Size size_;
        int quantity_;
        double price_;

        public string topping {
            get { return topping_.topping; }
            set { topping_.topping = value; }
        }

        public string size {
            get { return size_.size; }
            set { size_.size = value; }
        }

        public int quantity {
            get { return quantity_; }
            set { quantity_ = value; }
        }

        public double price {
            get { return price_; }
            set { price_ = value; }
        }

        public Pizza(Topping _topping, Size _size, int _quantity, double _price) {
            this.topping_ = _topping;
            this.size_ = _size;
            this.quantity_ = _quantity;
            double temp = _price;
            this.price_ = temp * quantity_;
        }
    }

    public class Manager {
        public ObservableCollection<Pizza> allPizzas = new ObservableCollection<Pizza>();
    }
}
