using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Xamarin.Forms;

namespace Assignment
{
    public partial class MainPage : ContentPage
    {
        private int pizza_total = 0;            //total amount of pizza in order
        private int pizza_quantity = 0;         //current amount selection
        private double pizza_price = 0;         //current price
        private double pizza_price_total = 0;   //total price
        private string mTopping = "";           //topping for current pizza
        private string mSize = "";              //size for current pizza

        //Observable list to handle all past + current order
        public ObservableCollection<PizzaManager> orderManager = new ObservableCollection<PizzaManager>();
        //Object to handle current order
        PizzaManager manager_ = new PizzaManager();

        ToppingManager toppingManager_ = new ToppingManager();
        SizeManager sizeManager_ = new SizeManager();

        public MainPage()
        {
            InitializeComponent();
            Topping.ItemsSource = toppingManager_.allToppings;
            Size.ItemsSource = sizeManager_.allSizes;
        } 

        public MainPage(PizzaManager pm_)
        {
            InitializeComponent();
            Topping.ItemsSource = toppingManager_.allToppings;
            Size.ItemsSource = sizeManager_.allSizes;

            manager_ = pm_;
            pizza_price_total = manager_.total;
            pizza_total = manager_.allPizzasManager.Count();
        }

        public MainPage(ObservableCollection<PizzaManager> ocpm)
        {
            InitializeComponent();
            Topping.ItemsSource = toppingManager_.allToppings;
            Size.ItemsSource = sizeManager_.allSizes;

            orderManager = ocpm;
        }

        async private void MyOrderClicked(object sender, EventArgs e)
        {
            //direct to Order Manager page
            await Navigation.PushAsync(new managerPage(manager_, orderManager));
        }

        private void ResetClicked(object sender, EventArgs e)
        {
            pizza_quantity = 0;
            pizza_price = 0;
            mTopping = "";
            mSize = "";
            Topping.SelectedItem = null;
            Size.SelectedItem = null;

            if (pizza_quantity == 0) {
                quantity.Text = "0";
                topping_.Text = "0";
                size_.Text = "0";
            }
        }

        private void AddClicked(object sender, EventArgs e)
        {         
            //set condition for button to display appropriately
            if (add.Text == "ADD") {
                if (mTopping != "" && mSize != "" && pizza_total >= 0) {
                    //add current quantity to order quantity
                    pizza_total += pizza_quantity;

                    //add pizza price (based on size) to total price
                    pizza_price_total += pizza_quantity * pizza_price;

                    //create a new pizza
                    Pizza temp = new Pizza(new Topping(mTopping), new Size(mSize), pizza_quantity, pizza_price);

                    //add a new PizzaManager data
                    manager_.addPizza(temp, pizza_price_total, pizza_total);
                    
                    _ = DisplayAlert("Success!!!", "Your order now has " + pizza_total + " pizza(s), and the total is " + pizza_price_total + " CAD", "OK");

                    quantity.Text = "none";
                    topping_.Text = "none";
                    size_.Text = "none";
                    mTopping = "";
                    mSize = "";
                    Topping.SelectedItem = null;
                    Size.SelectedItem = null;
                }
            }
        }

        private void quantity0(object sender, EventArgs e) {   
            pizza_quantity = 0;
            quantity.Text = "0";
            add.Text = "BUY";
        }
        private void quantity1(object sender, EventArgs e) {   
            pizza_quantity = 1;
            quantity.Text = "1";
            add.Text = "ADD";
        }
        private void quantity2(object sender, EventArgs e) {  
            pizza_quantity = 2;
            quantity.Text = "2";
            add.Text = "ADD";
        }
        private void quantity3(object sender, EventArgs e) {  
            pizza_quantity = 3;
            quantity.Text = "3";
            add.Text = "ADD";
        }
        private void quantity4(object sender, EventArgs e) { 
            pizza_quantity = 4;
            quantity.Text = "4";
            add.Text = "ADD";
        }
        private void quantity5(object sender, EventArgs e) { 
            pizza_quantity = 5;
            quantity.Text = "5";
            add.Text = "ADD";
        }
        private void quantity6(object sender, EventArgs e) {
            pizza_quantity = 6;
            quantity.Text = "6";
            add.Text = "ADD";
        }
        private void quantity7(object sender, EventArgs e) {
            pizza_quantity = 7;
            quantity.Text = "7";
            add.Text = "ADD";
        }
        private void quantity8(object sender, EventArgs e) {  
            pizza_quantity = 8;
            quantity.Text = "8";
            add.Text = "ADD";
        }
        private void quantity9(object sender, EventArgs e) {  
            pizza_quantity = 9;
            quantity.Text = "9";
            add.Text = "ADD";
        }

        private void Topping_ItemSelected(object sender, SelectedItemChangedEventArgs e)
        {
            if (e.SelectedItem != null) {
                mTopping = (e.SelectedItem as Topping).topping;
                topping_.Text = mTopping;
            }
        }

        private void Size_ItemSelected(object sender, SelectedItemChangedEventArgs e)
        {
            if (e.SelectedItem != null) {
                mSize = (e.SelectedItem as Size).size;
                size_.Text = mSize;
            }
           
            if (mSize == "Small")
                pizza_price = 9.99;
            else if (mSize == "Medium")
                pizza_price = 11.99;
            else if (mSize == "Large")
                pizza_price = 13.99;
            else if (mSize == "X-Large")
                pizza_price = 15.99;
            else if (mSize == "Party")
                pizza_price = 17.99;
        }
    }
}
