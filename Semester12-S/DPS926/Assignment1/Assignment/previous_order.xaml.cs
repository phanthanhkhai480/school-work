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
    public partial class previous_order : ContentPage
    {
        public ObservableCollection<PizzaManager> orderManager = new ObservableCollection<PizzaManager>();
        public previous_order(ObservableCollection<PizzaManager> obpm)
        {
            InitializeComponent();
            orderManager = obpm;
            orderHistory.ItemsSource = obpm;
        }
    }
}