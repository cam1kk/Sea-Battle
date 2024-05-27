#pragma once
#include <iostream>
using namespace std;

void winorlose(int player, int bot) {
	if (player > 0) {
		cout << "Player wins!" << endl;
	}
	else if (bot > 0) {
		cout << "Bot wins!" << endl;
	}
}
int letternumber(char letter) {
	if (letter == 'A') return 1;
	else if (letter == 'B') return 2;
	else if (letter == 'C') return 3;
	else if (letter == 'D') return 4;
	else if (letter == 'E') return 5;
	else if (letter == 'F') return 6;
	else if (letter == 'G') return 7;
	else if (letter == 'H') return 8;
	else if (letter == 'I') return 9;
	else if (letter == 'J') return 10;
}
-
public interface IDatabaseAdapter
{
    void InsertUser(User user);
    User FetchUser(int id);
    bool DeleteUser(int id);
    void ModifyUser(User user);
}

public class MsSqlDatabase
{
    public void InsertUser(User user) { }
    public User FetchUser(int id) { return null; }
    public bool DeleteUser(int id) { return true; }
    public void Modify(User user) { }
}

public class MsSqlDatabaseAdapter : IDatabaseAdapter
{
    private readonly MsSqlDatabase _msSqlDatabase;

    public MsSqlDatabaseAdapter(MsSqlDatabase msSqlDatabase)
    {
        _msSqlDatabase = msSqlDatabase;
    }

    public void InsertUser(User user)
    {
        _msSqlDatabase.InsertUser(user);
    }

    public User FetchUser(int id)
    {
        return _msSqlDatabase.FetchUser(id);
    }

    public bool DeleteUser(int id)
    {
        return _msSqlDatabase.DeleteUser(id);
    }

    public void ModifyUser(User user)
    {
        _msSqlDatabase.Modify(user);
    }
}

public class MySqlDatabase
{
    public void InsertUser(User user) { }
    public User GetUserById(int id) { return null; }
    public bool RemoveUser(int id) { return true; }
    public void Update(User user) { }
}

public class MySqlDatabaseAdapter : IDatabaseAdapter
{
    private readonly MySqlDatabase _mySqlDatabase;

    public MySqlDatabaseAdapter(MySqlDatabase mySqlDatabase)
    {
        _mySqlDatabase = mySqlDatabase;
    }

    public void InsertUser(User user)
    {
        _mySqlDatabase.InsertUser(user);
    }

    public User FetchUser(int id)
    {
        return _mySqlDatabase.GetUserById(id);
    }

    public bool DeleteUser(int id)
    {
        return _mySqlDatabase.RemoveUser(id);
    }

    public void ModifyUser(User user)
    {
        _mySqlDatabase.Update(user);
    }
}

public class PlSqlDatabase
{
    public void PushUser(User user) { }
    public User GetUser(int id) { return null; }
    public bool RemoveUser(int id) { return true; }
    public void Modify(object user) { }
}

public class PlSqlDatabaseAdapter : IDatabaseAdapter
{
    private readonly PlSqlDatabase _plSqlDatabase;

    public PlSqlDatabaseAdapter(PlSqlDatabase plSqlDatabase)
    {
        _plSqlDatabase = plSqlDatabase;
    }

    public void InsertUser(User user)
    {
        _plSqlDatabase.PushUser(user);
    }

    public User FetchUser(int id)
    {
        return _plSqlDatabase.GetUser(id);
    }

    public bool DeleteUser(int id)
    {
        return _plSqlDatabase.RemoveUser(id);
    }

    public void ModifyUser(User user)
    {
        _plSqlDatabase.Modify(user);
    }
}

public class User
{
    public int Id { get; set; }
    public string Name { get; set; }
}	
-

char numberletter(int number) {
	if (number == 1) return 'A';
	else if (number == 2) return 'B';
	else if (number == 3) return 'C';
	else if (number == 4) return 'D';
	else if (number == 5) return 'E';
	else if (number == 6) return 'F';
	else if (number == 7) return 'G';
	else if (number == 8) return 'H';
	else if (number == 9) return 'I';
	else if (number == 10) return 'J';
}
