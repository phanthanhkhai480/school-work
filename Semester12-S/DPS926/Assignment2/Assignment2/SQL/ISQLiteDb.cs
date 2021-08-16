using SQLite;

namespace Assignment2.SQL
{
    public interface ISQLiteDb
    {
        SQLiteAsyncConnection GetConnection();
    }
}
