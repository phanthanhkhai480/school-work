using Assignment2.SQL;
using SQLite;
using System.Collections.ObjectModel;
using System.Threading.Tasks;
using Xamarin.Forms;

namespace Assignment2.FlightModel
{
    public class DBManager
    {
        private SQLiteAsyncConnection _connection;
        public DBManager()
        {
            _connection = DependencyService.Get<ISQLiteDb>().GetConnection();
        }

        public async Task<ObservableCollection<QuoteManager>> CreateTable()
        {
            await _connection.CreateTableAsync<QuoteManager>();
            var todoTaskFromDB = await _connection.Table<QuoteManager>().ToListAsync();
            var allTasks = new ObservableCollection<QuoteManager>(todoTaskFromDB);
            return allTasks;
        }

        public void insertQuote(QuoteManager addQuote)
        {
            _connection.InsertAsync(addQuote);
        }

        public void deleteQuote(QuoteManager deleteQuote)
        {
            _connection.DeleteAsync(deleteQuote);
        }

        //public void updateQuote(QuoteManager toUpdate)
        //{
        //    _connection.UpdateAsync(toUpdate);
        //}
    }
}
