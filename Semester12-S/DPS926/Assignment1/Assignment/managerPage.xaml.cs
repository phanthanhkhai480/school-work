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
    
    public partial class managerPage : ContentPage
    {
        PizzaManager manager_;
        public ObservableCollection<PizzaManager> orderManager = new ObservableCollection<PizzaManager>();

        public managerPage(PizzaManager pm)
        {
            InitializeComponent();
            manager_ = pm;
        }

        public managerPage(PizzaManager pm, ObservableCollection<PizzaManager> ocpm) {
            InitializeComponent();
            manager_ = pm;
            orderManager = ocpm;
        }

        async private void check_currentOrder(object sender, EventArgs e)
        {
            await Navigation.PushAsync(new check_current_order(manager_, orderManager));
        }

        async private void update_currentOrder(object sender, EventArgs e)
        {
            if(manager_.allPizzasManager.Count() > 0)
                await Navigation.PushAsync(new MainPage(manager_));
            else
                _ = DisplayAlert("Error", "You don't have any pizza", "OK");
        }

        async private void previousOrder(object sender, EventArgs e)
        {
            await Navigation.PushAsync(new previous_order(orderManager));
        }

        async private void newOrder(object sender, EventArgs e)
        {
            await Navigation.PushAsync(new MainPage(orderManager));
        }
    }
}