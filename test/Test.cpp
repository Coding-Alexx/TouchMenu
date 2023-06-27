#include <Arduino.h>
#include <unity.h>
#include <../src/TouchMenuLib.h>

//Touch Menu Class Tests
void test_if_menu_has_no_screens_an_error_message_should_be_displayed(){

}

void test_if_overwritten_screen_id_deletes_the_old_screen_saved_under_this_id(){

}

void test_if_menu_has_been_initialized_before_a_screen_can_be_added(){

}

void test_after_switching_screens_if_the_new_screen_is_added_to_the_stack_as_long_as_the_new_screen_is_not_deactivated(){

}

void test_if_it_is_possible_to_go_back_to_the_previous_screen_on_the_stack(){

}

void test_if_it_is_possible_to_go_back_multiple_screens_on_the_stack(){

}

//Display Class Tests
void test_if_display_device_is_connected(){

}

void test_if_display_device_height_and_width_is_correct(){

}

//Screen Class Tests

void test_if_display_class_is_included_correctly(){

}

//Input Class Tests
void test_if_display_device_wit_a_touchscreen_is_recognised_as_such(){

}

void test_if_display_device_without_a_touchscreen_is_recognised_as_such(){

}

void test_if_input(){

}

//GridScreen Class Tests
void test_if_gridscreen_size_is_less_equal_the_size_of_the_display_device(){

}

void test_if_elements_dont_overlap(){

}

void test_if_grids_are_at_least_as_big_as_a_minium_size(){

}

void test_if_element_is_big_enough(){

}

void test_if_the_measurements_of_an_element_are_wrong_the_element_should_not_bew_drawn(){

}

void test_if_the_screen_has_a_display_resolution_before_an_element_can_be_added(){

}

void test_if_three_by_three_screen_places_an_element_indended_to_be_placed_in_the_middle_of_a_screen_in_the_actual_middle_of_the_display(){

}

//Elements Class Tests

void test_if_element_is_completly_on_screen_and_no_parts_of_it_are_outside_the_screen(){

}

void test_if_element_callback_is_only_called_when_the_hitbox_of_the_element_was_touched(){

}

//Color Wheel Class Tests

void test_if_amount_of_colors_is_between_6_and_255(){

}

void test_if_the_correct_colors_are_selected(){

}

//Sidebar Class Tests

void test_if_sidebar_does_not_cover_any_screens_and_their_elements(){

}

void test_compatability_of_the_sidebar_with_ELEMENT(){    //für jedes Element einen Test dieser Art

}

//Screensaver Class Tests

void test_if_screensaver_activates_with_no_inputs_after_a_certain_amount_of_time(){

}

void test_if_stack_is_being_cleared_besides_the_first_element(){

}

void test_if_screensaver_is_the_second_element_on_the_stack(){

}

void test_if_screensaver_doe_not_activate_with_inputs(){

}

void test_if_screensaver_timer_resets_after_inputs(){

}

void setup()
{
  // NOTE!!! Wait for >2 secs
  // if board doesn't support software reset via Serial.DTR/RTS
  
  delay(2000);

  UNITY_BEGIN(); // IMPORTANT LINE!
  RUN_TEST(test_if_menu_has_no_screens_an_error_message_should_be_displayed);
  UNITY_END();
}
/*
uint8_t i = 0;
uint8_t max_blinks = 5;
*/

void loop()
{
  /*
  if (i < max_blinks)
  {
    RUN_TEST(test_led_state_high);
    delay(500);
    RUN_TEST(test_led_state_low);
    delay(500);
    i++;
  }
  else if (i == max_blinks)
  {
    UNITY_END(); // stop unit testing
  }
  */
}
