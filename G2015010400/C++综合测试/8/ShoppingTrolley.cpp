#include <list>

class Commodity
{
public:
    ErrorCode modCommodity(const int& number){}//修改数量
private:
    int m_number;
    unsigned saleNumber = 1;
};



class ShoppingTrolley
{
public:
    ErrorCode Login(const int& user){}//用户登录
    ErrorCode addCommodity(const int& number){}//增加商品
    ErrorCode delCommodity(const int& number){}//删除商品
    ErrorCode clearShoppingTrolley(){}//清空购物车
    ErrorCode modCommodity(){}//生成订单
private:
    int m_number;
    list<Commodity> m_list;
    int m_user;
    
};

class Order
{
public:
    
private:
    int m_number;
    
};