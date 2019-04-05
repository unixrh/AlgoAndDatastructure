<?php
require_once("../common/stack.class.php");
class MinStack extends Stack {
  private $minArr = array();
  public function min() {
    if($this->size == 0) {
      echo "stack empty \n";
    } else {
      return $this->minArr[$this->size - 1];
    }
  }

  public function push($item) {
    if($this->size >= $this->limit) {
      echo "stack full \n";
      return;
    }
    $top = 65535;
    if($this->size > 0) {
      $top = $this->min();
    }
    if($item < $top)
      $this->minArr[] = $item;
    else 
      $this->minArr[] = $top;
    $this->stackArr[] = $item;
    $this->size++;
  }
}
define("NUM", 10);
$st = new MinStack(NUM);
var_dump($st);
$st->pop();
echo $st->top() . "\n";
for($i = 8; $i < NUM+3; $i++) {
  $st->push($i);
  echo "cur min: " . $st->min() . "\n";
}
for($i = 1; $i < NUM+3; $i++) {
  $st->push($i);
  echo "cur min: " . $st->min() . "\n";
}
while(!$st->isEmpty()) {
  echo $st->top() . "\n";
  echo "cur min: " . $st->min() . "\n";
  $st->pop();
}
?>
