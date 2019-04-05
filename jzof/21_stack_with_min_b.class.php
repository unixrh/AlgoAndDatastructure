<?php
require_once("../common/stack.class.php");
class MinStack {
  private $minSt  = NULL;
  private $dataSt = NULL;
  public function __construct($limit) {
    $this->minSt  = new Stack($limit);
    $this->dataSt = new Stack($limit);
  }

  public function top() {
    return $this->dataSt->top();
  }

  public function size() {
    $this->dataSt->size();
  }

  public function pop() {
    $this->minSt->pop();
    $this->dataSt->pop();
  }
  
  public function push($item) {
    $this->dataSt->push($item);
    $top = $this->minSt->top();
    if($item > $top) {
      $this->minSt->push($top);
    } else {
      $this->minSt->push($item);
    }
  }

  public function min() {
    return $this->minSt->top();
  }

  public function isEmpty() {
    return $this->dataSt->isEmpty();
  }
}

define("NUM", 10);
$st = new MinStack(NUM);
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
echo "cur size: " . $st->size() . "\n";
echo "====================\n";
for($i = 8; $i < NUM+3; $i++) {
  $st->push($i);
  echo "cur min: " . $st->min() . "\n";
}
echo "cur size: " . $st->size() . "\n";
while(!$st->isEmpty()) {
  echo $st->top() . "\n";
  echo "cur min: " . $st->min() . "\n";
  $st->pop();
}
?>
