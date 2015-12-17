#ifndef SOMETHING_H_INCLUDED
#define SOMETHING_H_INCLUDED

//#include <exception>
//#include <utility>

//template<int throw_at>
class something
{
public:
	something() : id(static_id++)
	{
//		if (id >= throw_at)
//		{
//			throw std::exception();
//		}
	}

	~something()
	{

	}

	// Copy CTor
	something(const something& sth) : id(sth.id)
	{
//		if (id == throw_at)
//		{
//			//cout << "Throw exeption when id is 3." << endl;
//			throw std::exception();
//		}
	}

//	// Move CTor
//    something(something&& sth) noexcept
//	{
//		sth.id = std::move(this->id);
////		if (sth.id >= throw_at)
////		{
////			throw std::exception();
////		}
//	}



private:
	int id;
	static int static_id;
	static const int throw_at = 3;
};

//template<int throw_at>
//int something<throw_at>::static_id = 0;

int something::static_id = 0;



#endif // SOMETHING_H_INCLUDED
