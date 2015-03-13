#ifndef INCLUDE_LED_TEST_H
#define INCLUDE_LED_TEST_H

class led6
{
public:
    static void init();
    static void on();
    static void off();
    static void toggle();
private:
    led6() = delete;
    led6(led6& other) = delete;
    led6& operator=(const led6& other) = delete;
};

class led7
{
public:
    static void init();
    static void on();
    static void off();
    static void toggle();
private:
    led7() = delete;
    led7(led6& other) = delete;
    led7& operator=(const led7& other) = delete;
};

#endif // INCLUDE_LED_TEST_H
