#!/bin/bash
sudo -u postgres psql <<"__END__"
DROP DATABASE journeyofdreams;
__END__
