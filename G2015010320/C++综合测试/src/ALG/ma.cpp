// the entry point for Q1 - Moving Average of algorithm final test

#include <iostream>
#include <deque>

class MovingAverage
{
private:
  double sum_;
  const int period_;
  std::deque<double> window_;

public:
  explicit MovingAverage(int period) : period_(period) { }
  double next(double num) {
    sum_ += num;
    window_.push_back(num);
    if (window_.size() > period_) {
      sum_ -= window_.front();
      window_.pop_front();
    }

    return sum_ / window_.size();
  }

public:
  virtual ~MovingAverage() { }
private:
  MovingAverage(const MovingAverage &);
  MovingAverage & operator= (const MovingAverage &);
};

int main()
{
  MovingAverage ma(2);
  std::cout << ma.next(1) << ", " << ma.next(3) << ", " << ma.next(4) << std::endl;
  return 0;
}