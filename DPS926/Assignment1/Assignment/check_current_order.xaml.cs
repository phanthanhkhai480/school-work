using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace Assignment
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class check_current_order : ContentPage
    {
        PizzaManager manager_;
        public ObservableCollection<PizzaManager> orderManager = new ObservableCollection<PizzaManager>();


        public check_current_order(PizzaManager pm, ObservableCollection<PizzaManager> ocpm)
        {
            InitializeComponent();
            manager_ = pm;
            orderManager = ocpm;
            amount.Text = "$" + manager_.total.ToString();
            quantity.Text = manager_.quantity.ToString();
            orderDisplay.ItemsSource = pm.allPizzasManager;
        }

        async private void place_order(object sender, EventArgs e)
        {
            if (manager_.allPizzasManager.Count() != 0) {
                //add currentOrder to Collection once user hit placedOrder
                orderManager.Add(manager_);

                //reset data to receive new data
                manager_.allPizzasManager.Clear();
                await Navigation.PushAsync(new managerPage(manager_, orderManager));
            }
            else
                _ = DisplayAlert("Error", "You don't have any pizza", "OK");
        }

        private void Delete_Button(object sender, EventArgs e)
        {
            var mPizza = (sender as MenuItem).CommandParameter as Pizza;
            manager_.deletePizza(mPizza);
            amount.Text = "$" + manager_.total.ToString();
            quantity.Text = manager_.quantity.ToString();
        }
    }
}