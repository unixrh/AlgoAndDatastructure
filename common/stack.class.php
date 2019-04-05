<?php
class Stack {
  private $limit;
  private $stackArr = array();
  protected $size = 0;
  public function __construct($limit) {
    $this->limit = $limit;
  }

  public function size(){
    return $this->size;
  }

  public function push($item) {
    if($this->size < $this->limit) {
      $this->stackArr[] = $item;
      $this->size++;
    } else {
      echo "stack full \n";
    }
  }

  public function pop() {
    if($this->size == 0) {
      echo "stack empty \n";
    } else {
      $this->size--;
    }
  }

  public function top() {
    if($this->size == 0) {
      echo "stack empty \n";
    } else {
      return $this->stackArr[$this->size - 1];
    }
  }

  public function isEmpty() {
    return !$this->size > 0;
  }
}

// test
define(NUM, 5);
$st = new Stack(NUM);
var_dump($st);
$st->pop();
echo $st->top() . "\n";
for($i = 1; $i < NUM+3; $i++)
  $st->push($i);
for($i = 1; $i < NUM+3; $i++) {
  echo $st->top() . "\n";
  $st->pop();
}
?>
